#pragma once
#include <string>

// COMMON
const int WEIGHT = 65;  // 80

const int SPEED = 40;  // 40

const int ENERGY = 100000;  // 100000

const int VARIABILITY = 20;

const float ENERGY_KOOF = 0.0025;  // 0.0025

const float ROT_SPEED = 100;

// HERBIVORS

const float REDUCE_HERB_KOOF = 1.5;
const int H_R = 0;
const int H_G = 155;
const int H_B = 255;

// PREDATORS

const float REDUCE_PRED_KOOF = 2.5;
const int P_R = 250;
const int P_G = 0;
const int P_B = 0;

// OMNIVORS
const float REDUCE_OMNI_KOOF = 1.5;
const int O_R = 255;
const int O_G = 165;
const int O_B = 0;

// FOOD

const int FOOD_COST = 17000;  // 20000

const int FOOD_SIZE = 5;  //

const int FOOD_PERIOD = 1;  // MINIMUM 1

const int FOOD_AMOUNT = 2;  // MINIMUM 1

// TECHNICS
const int WINDOW_HEIGHT = 1080;
const int WINDOW_WEIGHT = 1920;
const int SLIDES_PERIOD = 2;  // MINIMUM 1

// SCREEN
const int bg_R = 211, bg_G = 211, bg_B = 211;

const int RES_BUTTON_MARGIN_RIGHT = 250;
const int RES_BUTTON_MARGIN_TOP = 150;

const int SCORE_MARGIN_RIGHT = 270;
const int SCORE_MARGIN_TOP = 50;
const int SCORE_DH = 35;
const int SCORE_FONT_SIZE = 35;

// MENU
const int StartHeight = 50;
const int DHeight = 210;
const std::string PLAY_IMG_PATH = "../img/play.png";
const std::string ABOUT_IMG_PATH = "../img/about.png";
const std::string EXIT_IMG_PATH = "../img/exit.png";
const std::string RESTART_IMG_PATH = "../img/restart.png";
const std::string BG_IMG_PATH = "../img/back.jpg";

// ABOUT
const int ABOUT_R = 129, ABOUT_G = 181, ABOUT_B = 221;
const int ABOUT_TEXT_POSITION_X = 100;
const int ABOUT_TEXT_POSITION_Y = 100;
const int ABOUT_FONT_SIZE = 40;
const std::string ABOUT_INFO =
    "Click ESC to return into main menu\nYou can create new Herbivors(LMB), "
    "Predators(RMB) and Omnivors(click on mouse wheel)\nThe main goal is to "
    "create stable system\nMB it is Impossible\nHave a nice game";
const std::string ABOUT_FONT_PATH = ("../fonts/main_font.ttf");
