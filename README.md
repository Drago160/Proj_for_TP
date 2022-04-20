#Для сборки проекта пропишите в дирректории куда хотите поставть проект
git clone git@github.com:Drago160/Proj_for_TP.git  
cd Proj_for_TP  
git checkout checkpoint_2  
cd mytp_proj  
mkdir build  
cd build  
cmake ..  
make  
cd ../bin  
./SIM  
