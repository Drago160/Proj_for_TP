Для сборки проекта пропишите в дирректории куда хотите поставть проект


git clone git@github.com:Drago160/Proj_for_TP.git
cd Proj_for_TP
git checkout checkpoint_3
cd mytp_proj
sudo apt-get install libsfml-dev
mkdir build
cd build
cmake ..
make
cd ../bin
./SIM
