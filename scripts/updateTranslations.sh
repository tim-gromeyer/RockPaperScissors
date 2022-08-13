# change directory to the scripts parent directory
cd $( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )/..

# Update translations using lupdate
lupdate src/*.cpp ui/mainwindow.ui -ts translations/RockPaperScissors_de_DE.ts -noobsolete
