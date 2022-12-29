#include "Game.h"

#include <unistd.h>

#include <chrono>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>

#include "Controller.h"
#include "Drawer.h"
#include "SETTINGS.h"
#include "Spamer.h"
#include "Updater.h"
#include "menu.h"
#include "score.h"
#include "sfml.h"

Game::Game() {
  window.create(sf::VideoMode(WINDOW_WEIGHT, WINDOW_HEIGHT),
                "SIMULATION RUNS!!!");
  window.setFramerateLimit(60);
}

void Game::Restart() {
  foods.clear();
  herbivors.clear();
  omnivors.clear();
  predators.clear();
}

void Game::start() {
  sf::Clock clock;

  menu(window);

  //Инициализируем основные классы для управления/отрисовки
  Drawer drawer;
  FoodSpamer foodSpamer(clock);
  Controller controller;
  Updater updater;

  ///////////SCORE LABELS////////////////////
  sf::Font font;
  font.loadFromFile("../fonts/main_font.ttf");
  sf::Text text1("", font, SCORE_FONT_SIZE);
  sf::Text text2("", font, SCORE_FONT_SIZE);
  sf::Text text3("", font, SCORE_FONT_SIZE);
  text1.setFillColor(sf::Color{H_R, H_G, H_B});
  text2.setFillColor(sf::Color{P_R, P_G, P_B});
  text3.setFillColor(sf::Color{O_R, O_G, O_B});
  text1.setPosition(WINDOW_WEIGHT - SCORE_MARGIN_RIGHT, SCORE_MARGIN_TOP);
  text2.setPosition(WINDOW_WEIGHT - SCORE_MARGIN_RIGHT,
                    SCORE_MARGIN_TOP + SCORE_DH);
  text3.setPosition(WINDOW_WEIGHT - SCORE_MARGIN_RIGHT,
                    SCORE_MARGIN_TOP + SCORE_DH * 2);
  ///////////////////////////////////////////

  ///////////Button RESTART//////////////
  sf::Texture restartButton;

  restartButton.loadFromFile("../img/restartButton.png");
  sf::Sprite mainRestartButton(restartButton);

  mainRestartButton.setPosition(WINDOW_WEIGHT - RES_BUTTON_MARGIN_RIGHT,
                                RES_BUTTON_MARGIN_TOP);

  int restartButtonWidth = restartButton.getSize().x;
  int restartButtonHeight = restartButton.getSize().y;

  bool restartFlag = false;
  ////////////////////////////////

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
      if (event.type == sf::Event::KeyPressed)
        if (event.key.code == sf::Keyboard::Escape) {
          //Нажимаем на esc и выходим в меню
          int MenuFlag = menu(window);
          if (MenuFlag == 2) Restart();
        }
      if (event.type == sf::Event::MouseButtonPressed) {
        //Спам Unit'а на кнопку
        if (event.mouseButton.button == sf::Mouse::Middle) {
          int x = event.mouseButton.x;
          int y = event.mouseButton.y;
          Omnivor* omni = new Omnivor({(int)(x), (int)(y)});
          omnivors.push_back(omni);
        }
        if (event.mouseButton.button == sf::Mouse::Right) {
          int x = event.mouseButton.x;
          int y = event.mouseButton.y;
          Predator* w = new Predator({(int)(x), (int)(y)});
          predators.push_back(w);
        }

        if (event.mouseButton.button == sf::Mouse::Left) {
          int x = event.mouseButton.x;
          int y = event.mouseButton.y;
          Herbivor* e = new Herbivor({(int)(x), (int)(y)});
          herbivors.push_back(e);
        }
      }
    }

    ////////////Кнопка Restart/////////////////
    mainRestartButton.setColor(sf::Color::White);
    //Обрабатываем наведение и нажатие на кнопку
    if (sf::IntRect(WINDOW_WEIGHT - RES_BUTTON_MARGIN_RIGHT, RES_BUTTON_MARGIN_TOP, restartButtonWidth, restartButtonHeight)
            .contains(sf::Mouse::getPosition(window))) {
      mainRestartButton.setColor(sf::Color::Red);
      restartFlag = true;
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
      if (restartFlag) {
        Restart();
      }
    restartFlag = false;
    ///////////////////////////////////////////
    // BackGround
    window.clear(sf::Color(bg_R, bg_G, bg_B));

    //Спамим еду
    foodSpamer.update(foods);

    //Обновляем всех существ
    updater.UpdateHerb(herbivors, foods);
    updater.UpdatePred(predators, herbivors);
    updater.UpdateOmni(omnivors, foods, herbivors);

    //Контроль рождения и смертей
    controller.ControlHerb(herbivors);
    controller.ControlPred(predators);
    controller.ControlOmni(omnivors);

    //Рисуем Unit'ов т Food
    drawer.DrawFood(window, foods);
    drawer.DrawHerbivors(window, herbivors);
    drawer.DrawPredators(window, predators);
    drawer.DrawOmnivors(window, omnivors);

    //Выводим статистику
    score(window, "Omnivors: ", text3, omnivors.size());
    score(window, "Herbivors: ", text1, herbivors.size());
    score(window, "Predators: ", text2, predators.size());

    //Рисуем кнопку Restart
    window.draw(mainRestartButton);
    window.display();

    std::this_thread::sleep_for(std::chrono::milliseconds(SLIDES_PERIOD));
  }
}
