Для сборки проекта пропишите в дирректории куда хотите поставть проект

sudo apt-get install libsfml-dev  
git clone git@github.com:Drago160/Proj_for_TP.git  
cd Proj_for_TP  
git checkout develop  
cd mytp_proj  
mkdir build  
cd build  
cmake ..  
make  
cd ../bin  
./SIM  
