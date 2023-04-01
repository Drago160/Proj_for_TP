#include "menu.h"

#include "SETTINGS.h"

using namespace sf;

//в зависимости от номера надписи подбирает высоту для ее отрисовки
int label_height(int count) { return StartHeight + (count - 1) * DHeight; }

//вызывает меню(возвращает флаги для некоторых действий в зависимости от нажатой
//кнопки
int menu(RenderWindow& window) {
  Texture menuTexturePlay, menuTextureAbout, menuTextureExit,
      menuTextureRestart, aboutTexture, menuBackground;

  //подгружаем картинки для кнопок
  menuTexturePlay.loadFromFile(PLAY_IMG_PATH);
  menuTextureAbout.loadFromFile(ABOUT_IMG_PATH);
  menuTextureExit.loadFromFile(EXIT_IMG_PATH);
  menuTextureRestart.loadFromFile(RESTART_IMG_PATH);
  menuBackground.loadFromFile(BG_IMG_PATH);

  //Главные кнопки
  Sprite menuPlay(menuTexturePlay), menuAbout(menuTextureAbout),
      menuExit(menuTextureExit), menuRestart(menuTextureRestart),
      about(aboutTexture), menuBg(menuBackground);

  //это размеры соответствующих кнопок
  int playWidth = menuTexturePlay.getSize().x;
  int playHeight = menuTexturePlay.getSize().y;

  int resWidth = menuTextureRestart.getSize().x;
  int resHeight = menuTextureRestart.getSize().y;

  int aboutWidth = menuTextureAbout.getSize().x;
  int aboutHeight = menuTextureAbout.getSize().y;

  int exitWidth = menuTextureExit.getSize().x;
  int exitHeight = menuTextureExit.getSize().y;

  bool isMenu = 1;
  int menuNum = 0;

  //ставим кнопку на нужное место
  menuPlay.setPosition(WINDOW_WEIGHT / 2 - playWidth / 2, label_height(1));
  menuRestart.setPosition(WINDOW_WEIGHT / 2 - resWidth / 2, label_height(2));
  menuAbout.setPosition(WINDOW_WEIGHT / 2 - aboutWidth / 2, label_height(3));
  menuExit.setPosition(WINDOW_WEIGHT / 2 - exitWidth / 2, label_height(4));
  menuBg.setPosition(0, 0);

  while (isMenu) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
        isMenu = false;
      }
    }
    menuPlay.setColor(Color::White);
    menuAbout.setColor(Color::White);
    menuExit.setColor(Color::White);
    menuRestart.setColor(Color::White);
    menuNum = 0;
    window.clear(Color(ABOUT_R, ABOUT_G, ABOUT_B));

    //Обработка наведения курмора на кнопку
    if (IntRect(WINDOW_WEIGHT / 2 - playWidth / 2, label_height(1), playWidth,
                playHeight)
            .contains(Mouse::getPosition(window))) {
      menuPlay.setColor(Color::Red);
      menuNum = 1;
    }

    if (IntRect(WINDOW_WEIGHT / 2 - resWidth / 2, label_height(2), resWidth,
                resHeight)
            .contains(Mouse::getPosition(window))) {
      menuRestart.setColor(Color::Red);
      menuNum = 4;
    }

    if (IntRect(WINDOW_WEIGHT / 2 - aboutWidth / 2, label_height(3), aboutWidth,
                aboutHeight)
            .contains(Mouse::getPosition(window))) {
      menuAbout.setColor(Color::Red);
      menuNum = 2;
    }

    if (IntRect(WINDOW_WEIGHT / 2 - exitWidth / 2, label_height(4), exitWidth,
                exitHeight)
            .contains(Mouse::getPosition(window))) {
      menuExit.setColor(Color::Red);
      menuNum = 3;
    }

    //Нажали на кнопку
    if (Mouse::isButtonPressed(Mouse::Left)) {
      if (menuNum == 1) isMenu = false;
      if (menuNum == 2) {
        window.draw(about);
        window.display();
        _about(window, isMenu);
      }

      if (menuNum == 3) {
        isMenu = false;
        window.close();
      }

      if (menuNum == 4) {
        isMenu = false;
        return 2;
      }
    }
    //Рисуем Bg и кнопки
    window.draw(menuBg);
    window.draw(menuPlay);
    window.draw(menuAbout);
    window.draw(menuExit);
    window.draw(menuRestart);
    window.display();
  }

  return 1;
}
