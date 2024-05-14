

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include <time.h>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"

using namespace sf;
using namespace std;
//bool leftMovePermission();
//bool rightMovepermission();
//bool checkPosition(int  arr[4]);
bool showmenuimage = true, game_over = false,  space = false, firstlevel = true, secondlevel = false, high_score = false,Help=false,pausepp=false,new_game=false;
bool showgrid = false; 
int highScore=1;
Music music;
void readFile();
//void removebox();
void writeFile(int);
Text TextFormation(const std::string& str, unsigned int characterSize, sf::Uint32 style, const sf::Color& fillColor, const sf::Vector2f& position, const sf::Font& font) {
    Text text10;
    text10.setFillColor(fillColor); // Set the fill color
    text10.setStyle(style);
    text10.setFont(font);
    text10.setPosition(position);
    text10.setString(str);
    text10.setCharacterSize(characterSize);
    return text10;
}
int main() {
    srand(time(0));//15*35
    
    RenderWindow window(VideoMode(35*25, 35*20), "Amir Shahzad");
    Texture obj1, obj2, obj3,obj4,Box;
   
    Sprite sprite(obj1), background(obj2), frame(obj3),spr(obj4),game(Box);
    Texture texture1,texture2,texture3,texture4,texture5,help1,pause1,highScoreimg;
    
  
    texture1.loadFromFile("img/pic12.png");
    texture2.loadFromFile("img/Menu6.jpg");
    texture3.loadFromFile("img/over.jpeg");
    texture4.loadFromFile("img/instruction.jpeg");
    texture5.loadFromFile("img/pause.png");
    help1.loadFromFile("img/Help.jpg");
    pause1.loadFromFile("img/Pause1.jpeg");
    highScoreimg.loadFromFile("img/HighScore.jpeg");

    music.openFromFile("music/Amirmusic.mp3 ");
    music.play();

    Sprite Menu(texture2);
    Sprite sprite1(texture1);
    Sprite sprite3(texture3);
    Sprite sprite4(texture4);
    Sprite sprite5(texture5);
    Sprite help2(help1);
    Sprite pause1Spr(pause1);
    Sprite highScoreimgSpr(highScoreimg);
    ofstream writeFile1;
    writeFile1.open("record.bin",ios:: app);
    int num = 10;
    for (int i = 0;i < 10;i++) {
         num = 100-(i*10);
        writeFile1.write(reinterpret_cast<char*>(&num), sizeof(num));
    }
    writeFile1.close();


    Menu.setScale(window.getSize().x / Menu.getLocalBounds().width,
        window.getSize().y / Menu.getLocalBounds().height);
    int delta_x = 0, colorNum = 1;
    float timer = 50, delay = 0.3;
    bool rotate = 0;
    Clock clock;
    RectangleShape square(Vector2f(35, 35));
    float delayBetweenFrames=0.9;
    


    float temp;
    // Array to hold sf::Color objects
     // Array to hold sf::Color objects for each block
    sf::Color lightBlue(173, 216, 230); // Light Blue (Red: 173, Green: 216, Blue: 230)
    sf::Color brown(165, 42, 42); // Brown (Red: 165, Green: 42, Blue: 42)
    sf::Color orange(255, 165, 0); // Orange (Red: 255, Green: 165, Blue: 0)
    sf::Color purple(128, 0, 128);
    sf::Color darkBlue(0, 0, 128); // Dark Blue (Red: 0, Green: 0, Blue: 128)
    sf::Color darkRed(128, 0, 0); // Dark Red (Red: 128, Green: 0, Blue: 0)
    sf::Color colors[] = {
        sf::Color::Red,
        sf::Color::Green,
        sf::Color::Blue,
        orange,
        sf::Color::Cyan,
        sf::Color::Magenta,
        lightBlue,  // Add light blue color here
        sf::Color::Black
    };
    //sf::Color lightBlue(173, 216, 230); // Light Blue (Red: 173, Green: 216, Blue: 230)

    int shapeCount = 0;
    bool bombCreated = false;
    int bombColor=1;
    int bombRow = -1;
    int bombColumn = -1;
    /// firstly at start read Highscore
   /* ofstream writeFile;
    writeFile.open("record.bin", ios::app);*/
    
    readFile();
    cout << "High Score is " << highScore << endl;
    //int idx=0;*/
    while (window.isOpen()) {
       
        sf::Font Amir;
        Amir.loadFromFile("font/malgun_boot.ttf");
        Text startgame = TextFormation("Start New game ", 40, Text::Bold | Text::Bold, Color::Red, Vector2f(275, 170), Amir);
        Text selectlevel = TextFormation("Select Level ", 60, Text::Bold | Text::Bold, Color::Red, Vector2f(265, 250), Amir);
        Text level1 = TextFormation("Level 1 ", 40, Text::Bold | Text::Bold, Color::Black, Vector2f(350, 310), Amir);
        Text level2 = TextFormation("Level 2 ", 40, Text::Bold | Text::Bold, Color::Black, Vector2f(350, 355), Amir);
        Text highscore = TextFormation("See High_Scores ", 40, Text::Bold | Text::Bold, Color::Red, Vector2f(265, 450), Amir);
        Text help = TextFormation("Help ", 40, Text::Bold | Text::Bold, Color::Red, Vector2f(390, 540), Amir);
        Text exit = TextFormation("Exit ", 40, Text::Bold | Text::Bold, Color::Red, Vector2f(390, 620), Amir);
        Text back = TextFormation("Back ", 30, Text::Bold | Text::Bold, Color::White, Vector2f(55, 229), Amir);
        Text back1 = TextFormation("Back to menu ", 30, Text::Bold | Text::Bold, Color::White, Vector2f(28, 35), Amir);
        Text continuep = TextFormation("Continue", 30, Text::Bold | Text::Bold, Color::White, Vector2f(360, 80), Amir);
        Text newgamep = TextFormation("Start new Game ", 30, Text::Bold | Text::Bold, Color::White, Vector2f(330, 205), Amir);
        Text highscorep = TextFormation("See Heighest score ", 30, Text::Bold | Text::Bold, Color::White, Vector2f(310, 335), Amir);
        Text exitp = TextFormation("Exit Game ", 30, Text::Bold | Text::Bold, Color::White, Vector2f(360, 458), Amir);
        Text continueo = TextFormation("Your Score", 50, Text::Bold | Text::Bold, Color::Red, Vector2f(245, 310), Amir);
        Text newgameo = TextFormation(" Restarts", 50, Text::Bold | Text::Bold, Color::Red, Vector2f(285, 400), Amir);
        Text highscoreo = TextFormation("See Heighest ", 50, Text::Bold | Text::Bold, Color::Red, Vector2f(235, 500), Amir);
        Text exito = TextFormation(" Game Exit ", 50, Text::Bold | Text::Bold, Color::Red, Vector2f(280, 600), Amir);
        if (firstlevel)
        { 
            delayBetweenFrames = 0.5;
        }
        else
        {
            delayBetweenFrames = 0.4;
        }
        
        if (delayBetweenFrames != 0.00000000001f)
        {
            temp = delayBetweenFrames;
        }
        
      
        float time = clock.restart().asSeconds();
        float time1 = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time1;

            sf::Event e;
            while (window.pollEvent(e))
            {

                if (e.type == sf::Event::Closed)
                    window.close();

                if (e.type == Event::MouseButtonPressed) {
                    Vector2i mousePosition = Mouse::getPosition(window);
                    if (startgame.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                       // cout << "Hy";
                        showmenuimage = false;
                        showgrid = true;
                    }
                    else if (level1.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                       // cout << "Hy";
                        showmenuimage = false;
                        showgrid = true;
                        firstlevel = true;
                    }
                    else if (level2.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        cout << "level2" << endl;;
                        showmenuimage = false;
                        showgrid = true;
                        secondlevel = true;
                        firstlevel = false;
                    }
                    else if (highscore.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        //cout << "Hy";
                        showmenuimage = false;
                        high_score = true;
                        
                    }
                    else if (help.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        showmenuimage = false;
                        Help = true;
                    }
                    else if (exit.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                       // cout << "Hy";
                        showmenuimage = false;
                        return 0;
                    }
                    else if (back.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        // cout << "Hy";
                        Help = false;
                        showmenuimage = true;
                       
                    }
                    else if (back1.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        // cout << "Hy";
                        high_score = false;
                        showmenuimage = true;

                    }
                    else if (continuep.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        // cout << "Hy";
                        pausepp = false;
                        showgrid = true;

                    }
                    else if (newgamep.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        // cout << "Hy";
                        for (int i = 0;i < 20;i++) {
                            for (int j = 0;j < 15;j++) {
                                gridArray[i][j] = 0;
                                colorOfGrid[i][j] = 7;
                            }
                        }
                        level = 1;
                        line = 0;
                        score = 0;

                        pausepp = false;
                        showgrid = true;

                    }
                    else if (highscorep.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        // cout << "Hy";
                        pausepp = false;
                        high_score = true;

                    }
                    else if (exitp.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        // cout << "Hy";
                        return 0;
                        pausepp = false;
                        showgrid = false;
                        

                    }
                    
                    else if (newgameo.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        
                        
                        for (int i = 0;i < 20;i++) {
                            for (int j = 0;j < 15;j++) {
                                gridArray[i][j] = 0;
                                colorOfGrid[i][j] = 7;
                            }
                        }
                        level = 1;
                        line = 0;
                        score = 0;

                        game_over = false;
                        showgrid = true;

                    }
                    else if (highscoreo.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                       
                        high_score = true;
                        game_over = false;

                    }
                    else if (exito.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        game_over = false;
                        return 0;

                    }

                }
                if (e.type == Event::MouseMoved) {
                    // Get the current mouse position relative to the window
                    Vector2i mousePosition = Mouse::getPosition(window);

                    cout << "Mouse X ; " << mousePosition.x << " , Mouse Y : " << mousePosition.y << endl;
                }

                if (e.type == Event::KeyPressed)
                {
                    if (e.key.code == Keyboard::Up)
                    {
                        int tempArrX[4];
                        int tempArrY[4];
                        // for x
                        int r = boxSelectionX[0];
                        for (int i = 0;i < 4;i++) {
                            tempArrX[i] = r + (boxSlelectionY[i] - boxSlelectionY[0]);
                        }
                        // for y
                        r = boxSlelectionY[0];
                        for (int i = 0;i < 4;i++) {
                            tempArrY[i] = r + (boxSelectionX[i] - boxSelectionX[0]);
                        }

                        // remove 
                        removebox();
                        /*  for (int i = 0;i < 4;i++) {
                              gridArray[boxSlelectionY[i]][boxSelectionX[i]] = 0;
                              colorOfGrid[boxSlelectionY[i]][boxSelectionX[i]] = 7;
                          }*/
                        for (int i = 0;i < 4;i++) {
                            boxSelectionX[i] = tempArrX[i];
                            boxSlelectionY[i] = tempArrY[i];
                        }
                        // add
                        for (int i = 0;i < 4;i++) {
                            gridArray[boxSlelectionY[i]][boxSelectionX[i]] = 1;
                            colorOfGrid[boxSlelectionY[i]][boxSelectionX[i]] = n;

                        }

                    }
                    else if (e.key.code == Keyboard::Left) {
                        if (leftMovePermission()) {
                            removebox();
                            for (int i = 0;i < 4;i++)
                            {
                                boxSelectionX[i] -= 1;
                            }
                        }
                        // add
                        for (int i = 0;i < 4;i++) {
                            gridArray[boxSlelectionY[i]][boxSelectionX[i]] = 1;
                            colorOfGrid[boxSlelectionY[i]][boxSelectionX[i]] = n;

                        }
                    }
                    else if (e.key.code == Keyboard::Right) {
                        if (rightMovepermission())
                        {
                            removebox();
                            for (int i = 0;i < 4;i++)
                            {
                                boxSelectionX[i] += 1;
                            }
                        }
                        // add
                        for (int i = 0;i < 4;i++) {
                            gridArray[boxSlelectionY[i]][boxSelectionX[i]] = 1;
                            colorOfGrid[boxSlelectionY[i]][boxSelectionX[i]] = n;
                        }
                    }

                   // for space down 
                    if (e.key.code == Keyboard::Space) {
                        space = true;
                    }
                    //#is in keypressed forlder
                    if (e.key.code == Keyboard::P) {
                        
                        pausepp = true;
                        showgrid = false;
                }
                    if (Keyboard::isKeyPressed(Keyboard::Down))   //Just another way to detect key presses without event listener
                    {
                        delayBetweenFrames = 0.00000000001f;//0.1
                    }
                    else {
                        delayBetweenFrames = temp;
                    }

                }
                

            }
            if (showmenuimage) {
                window.clear();
                window.draw(Menu);
                window.draw(startgame);
                window.draw(selectlevel);
                window.draw(level1);
                window.draw(level2);
                window.draw(highscore);
                window.draw(help);
                window.draw(exit);
                window.display();
            }
            if (high_score)
            {
                window.clear();
                sf::Vector2u windowSize = window.getSize();
                sf::Vector2f imageSize = highScoreimgSpr.getLocalBounds().getSize();

                float scaleX = windowSize.x / imageSize.x;
                float scaleY = windowSize.y / imageSize.y;

                highScoreimgSpr.setScale(scaleX, scaleY);

                window.draw(highScoreimgSpr);
                window.draw(back1);
                
                for (int i = 0;i < 10;i++) {
                     
                    Text score = TextFormation(to_string(scoreArray[i]), 50, Text::Bold | Text::Bold, Color::White, Vector2f(275, 10 + (i * 50)), Amir);
                    window.draw(score);
                }
                window.display();

            }
            if (Help)
            {
                window.clear();
                sf::Vector2u windowSize = window.getSize();
                sf::Vector2f imageSize = help2.getLocalBounds().getSize();

                float scaleX = windowSize.x / imageSize.x;
                float scaleY = windowSize.y / imageSize.y;
                help2.setScale(scaleX, scaleY);
               
                window.draw(help2);
                window.draw(back);
                window.display();
            }
            if (pausepp)
            {
                window.clear();
                sf::Vector2u windowSize = window.getSize();
                sf::Vector2f imageSize = pause1Spr.getLocalBounds().getSize();
                float scaleX = windowSize.x / imageSize.x;
                float scaleY = windowSize.y / imageSize.y;
                pause1Spr.setScale(scaleX, scaleY);
                window.draw(pause1Spr);
                window.draw(continuep);
                window.draw(newgamep);
                window.draw(highscorep);
                window.draw(exitp);
                window.display();

            }
            
            






                //If DOWN key is pressed,delay in falling piece decreases from 0 to 0.05


                ///////////////////////////////////////////////
                ///*** START CALLING YOUR FUNCTIONS HERE ***///
               // fallingPiece(timer, delay, colorNum); //faling piece function

                if (showgrid) {
                    window.clear();
                    window.draw(sprite1);

                    if (check == false) {
                        // check is just for initial
                        for (int i = 0;i < 20;i++) {
                            for (int j = 0;j < 15;j++) {
                                gridArray[i][j] = 0;
                                colorOfGrid[i][j] = 7;

                            }
                        }
                    }

                    // for space
                    if (space == true) {
                        // remove shape
                        for (int i = 0;i < 4;i++) {
                            gridArray[boxSlelectionY[i]][boxSelectionX[i]] = 0;
                            colorOfGrid[boxSlelectionY[i]][boxSelectionX[i]] = 7;
                        }
                        while (checkPosition(boxSlelectionY)) {
                            for (int i = 0;i < 4;i++) {
                                boxSlelectionY[i] += 1;
                            }
                        }

                        // add next 
                        for (int i = 0;i < 4;i++) {
                            gridArray[boxSlelectionY[i]][boxSelectionX[i]] = 1;
                            colorOfGrid[boxSlelectionY[i]][boxSelectionX[i]] = n;


                        }
                        space = false;
                    }

                    int tempArrToShadow[4];
                    for (int i = 0;i < 4;i++) {
                        tempArrToShadow[i] = boxSlelectionY[i];
                    }
                    // for shadow
                    while (checkPosition(tempArrToShadow)) {
                        for (int i = 0;i < 4;i++) {
                            tempArrToShadow[i] += 1;
                        }
                    }
                    for (int i = 0;i < 4;i++) {


                        square.setPosition(boxSelectionX[i] * 35, tempArrToShadow[i] * 35);
                        square.setOutlineColor(Color::Yellow);
                        square.setFillColor(Color(50, 50, 50));
                        square.setOutlineThickness(1.0f);

                        window.draw(square);

                    }
                    // move next
                    if (checkPosition(boxSlelectionY) && check == true) {

                        // remove shape
                        for (int i = 0;i < 4;i++) {
                            removebox();
                            // gridArray[boxSlelectionY[i]][boxSelectionX[i]] = 0;
                            colorOfGrid[boxSlelectionY[i]][boxSelectionX[i]] = 7;

                        }
                        // add next 
                        for (int i = 0;i < 4;i++) {
                            boxSlelectionY[i] += 1;                 // move to next row
                            gridArray[boxSlelectionY[i]][boxSelectionX[i]] = 1;
                            colorOfGrid[boxSlelectionY[i]][boxSelectionX[i]] = n;
                        }
                    }
                    else
                    {
                        if (check == true) {
                            for (int i = 0;i < 4;i++) {
                                if (colorOfGrid[boxSlelectionY[i]][boxSelectionX[i]] == colorOfGrid[boxSlelectionY[i]][boxSelectionX[i] + 1])
                                    score += 3;
                                if (colorOfGrid[boxSlelectionY[i]][boxSelectionX[i]] == colorOfGrid[boxSlelectionY[i]][boxSelectionX[i] - 1])
                                    score += 3;
                                if (colorOfGrid[boxSlelectionY[i]][boxSelectionX[i]] == colorOfGrid[boxSlelectionY[i]+1][boxSelectionX[i]])
                                    score += 3;
                                if (colorOfGrid[boxSlelectionY[i]][boxSelectionX[i]] == colorOfGrid[boxSlelectionY[i] - 1][boxSelectionX[i]])
                                    score += 3;
           
                            }
                            switch (n) {
                      
                            case 3:
                           
                                score -= 24;
                                break;
                            default:
                                score -= 18;break;
                            
                            }
                        }
                        check = true;

                        // new shape
                        shapeCount++;
                        if (firstlevel)
                        {
                            n = rand() % 4;
                        }
                        else if (secondlevel)
                        {
                            n = rand() % 7;
                        }
                        else {
                            n = rand() % 7;
                        }
                        //idx = n;

                        /*if (n == 0)
                        {
                            score += 30;
                        }
                        else  if (n == 1)
                        {
                            score += 18;
                        }
                        else  if (n == 2)
                        {
                            score += 24;
                        }
                        else  if (n == 3)
                        {
                            score += 37;
                        }
                        else  if (n == 4)
                        {
                            score += 17;
                        }
                        else  if (n == 5)
                        {
                            score += 23;
                        }
                        else  if (n == 6)
                        {
                            score += 28;
                        }*/


                        for (int i = 0;i < 4;i++) {
                            boxSelectionX[i] = BlockColumns[n][i];
                            boxSlelectionY[i] = BlockKSRows[n][i];
                        }

                        if (checkGameOver()) {
                            // Game over condition is met 
                            writeFile(score);
                            showgrid = false;

                            game_over = true;
                            // Optionally set the game_over flag to true
                        }
                        //  }
                        if (game_over) {
                            window.clear();
                            cout << "Gameover" << endl;
                            sprite5.setScale(window.getSize().x / sprite5.getLocalBounds().width,
                                window.getSize().y / sprite5.getLocalBounds().height);
                            window.draw(sprite5);
                            // Calculate the desired y-axis scale
                            float desiredYScale = window.getSize().y / sprite3.getLocalBounds().height;

                            // Set the y-axis scale
                            sprite3.setScale(sprite3.getScale().x, desiredYScale);

                            // Adjust the position to center the image
                            sprite3.setPosition((window.getSize().x - sprite3.getGlobalBounds().width) / 2,
                                (window.getSize().y - sprite3.getGlobalBounds().height) / 2);
                            window.draw(sprite3);
                            window.draw(continueo);
                            window.draw(newgameo);
                            window.draw(highscoreo);
                            window.draw(exito);
                           // window.display();


                            sf::Font font;
                            font.loadFromFile("font/malgun_boot.ttf");
                            sf::Text text;
                            text.setFont(font); // Set the font
                            text.setPosition(510, 310);
                            text.setCharacterSize(50); // Set the character size
                            text.setFillColor(sf::Color::Blue); // Set the text color
                            text.setString(to_string(score)); // Set the string to display
                            text.setStyle(sf::Text::Bold);
                            window.draw(text);

                        }
                        for (int i = 0;i < 4;i++)
                        {
                            gridArray[boxSlelectionY[i]][boxSelectionX[i]] = 1;
                            colorOfGrid[boxSlelectionY[i]][boxSelectionX[i]] = n;


                        }

                    }
                  

                    // for bomb creation
            // 
             // bomb update axis
                    if (bombCreated == true) {
                        cout << "In bomb" << endl;
                        gridArray[bombRow][bombColumn] = 0;
                        bombRow += 1;
                        gridArray[bombRow][bombColumn] = 9;
                    }
                    
                    if (shapeCount == 10) {
                        if(firstlevel)
                        bombColor = rand() % 4;
                        else if(secondlevel)
                        bombColor = rand() % 7;
                       
                        cout << "Here" <<bombColor <<endl;;
                        bool shapeCheckForBomb;
                        do {
                            shapeCheckForBomb = false;
                            bombColumn = rand() % 15;
                            for (int i = 0;i < 4;i++) {
                                if (boxSelectionX[i] == bombColumn) {
                                    shapeCheckForBomb = true;
                                    break;
                                }
                            }
                        } while (shapeCheckForBomb == true);
                        bombRow = 0;
                        gridArray[0][bombColumn] = 9;     // 9 for bomb identifier
                        shapeCount = 0;
                        bombCreated = true;
                    }


                    // bomb check each time 
                    if (bombCreated == true) {
                        for (int i = 0;i < 4;i++) {
                            bool isShape = false;

                            if (gridArray[bombRow + 1][bombColumn] == 19) { // bottom boundary
                                gridArray[bombRow][bombColumn] = 0;
                                bombCreated = false;
                                break;
                            }
                            else if (gridArray[bombRow + 1][bombColumn] == 1) {

                                if (colorOfGrid[bombRow + 1][bombColumn] == bombColor) {
                                    for (int i = 0;i < 20;i++) {
                                        for (int j = 0;j < 15;j++) {
                                            gridArray[i][j] = 0;
                                            colorOfGrid[i][j] = 7;
                                        }
                                    }
                                    score = score + 50;
                                }
                                else {
                                    gridArray[bombRow][bombColumn] = 0; // to remove bomb itself
                                    // remove bomb neighbours
                                    gridArray[bombRow][bombColumn + 1] = 0;
                                    gridArray[bombRow][bombColumn - 1] = 0;
                                    gridArray[bombRow + 1][bombColumn] = 0;
                                    gridArray[bombRow + 2][bombColumn] = 0;
                                    for (int i = bombRow;i > 0;i--) {
                                        gridArray[i][bombColumn + 1] = gridArray[i - 1][bombColumn + 1];
                                        gridArray[i][bombColumn - 1] = gridArray[i - 1][bombColumn - 1];
                                    }
                                    gridArray[0][bombColumn + 1] = 0;
                                    gridArray[0][bombColumn - 1] = 0;
                                    // remove color 
                                    colorOfGrid[bombRow][bombColumn + 1] = 7;
                                    colorOfGrid[bombRow][bombColumn - 1] = 7;
                                    colorOfGrid[bombRow + 1][bombColumn] = 7;
                                    colorOfGrid[bombRow + 2][bombColumn] = 7;
                                    for (int i = bombRow;i > 0;i--) {
                                        colorOfGrid[i][bombColumn + 1] = colorOfGrid[i - 1][bombColumn + 1];
                                        colorOfGrid[i][bombColumn - 1] = colorOfGrid[i - 1][bombColumn - 1];
                                    }
                                    colorOfGrid[0][bombColumn + 1] = 7;
                                    colorOfGrid[0][bombColumn - 1] = 7;

                                }
                                bombCreated = false;//down position
                                break;
                            }
                        }
                    }
                    // remove line
                    int temp1 = 0;
                    int lineCount = 0;

                    for (int i = 0;i < 19;i++)
                    {
                        temp1 = 0;
                        for (int j = 0;j < 15;j++)
                        {
                            if (gridArray[i][j] == 1)
                            {
                                temp1++;
                            }
                        }
                        if (temp1 == 15)
                        {
                            line++;
                           lineCount++;
                            for (int k = 0;k < 15;k++)
                            {
                                gridArray[i][k] = 0;
                                colorOfGrid[i][k] = 7;

                            }
                            for (int r = i;r >= 0;r--) {
                                for (int j = 0;j < 15;j++) {
                                    if (r == 0) {
                                        gridArray[r][j] = 0;
                                        colorOfGrid[r][j] = 7;
                                    }
                                    else {
                                        gridArray[r][j] = gridArray[r - 1][j];
                                        colorOfGrid[r][j] = colorOfGrid[r - 1][j];
                                    }

                                }
                            }
                            for (int a = 0;a < 4;a++)
                                boxSlelectionY[a] += 1;
                            // to remove 
                          
                        }
                    }
                   if(line!=0 && lineCount!=0)
                    score +=( (20 * lineCount) - 10);
                    if (score >=50 && firstlevel==true)
                    {
                        level++;
                        secondlevel = true;
                        firstlevel = false;
                      
                    }


                    //Example: fallingPiece() function is called here
                     ///*** YOUR CALLING STATEMENTS END HERE ***///
                     /////////////////////////////////////////////


                    if (showmenuimage) {
                        // window.clear();

                        window.draw(Menu);
                        window.draw(startgame);
                        // window.display();
                    }
                    if (game_over != true)
                    {
                        sf::Font font1;
                        font1.loadFromFile("font/malgun_boot.ttf");
                        sf::Text text1;
                        text1.setFont(font1); // Set the font
                        text1.setPosition(620, 55);
                        text1.setCharacterSize(50); // Set the character size
                        text1.setFillColor(sf::Color::White); // Set the text color
                        text1.setString("SCORE"); // Set the string to display
                        text1.setStyle(sf::Text::Bold);
                        window.draw(text1);

                        sf::Font font;
                        font.loadFromFile("font/malgun_boot.ttf");
                        sf::Text text;
                        text.setFont(font); // Set the font
                        text.setPosition(645, 140);
                        text.setCharacterSize(50); // Set the character size
                        text.setFillColor(sf::Color::White); // Set the text color
                        text.setString(to_string(score)); // Set the string to display
                        text.setStyle(sf::Text::Bold);
                        window.draw(text);

                        sf::Font font2;
                        font2.loadFromFile("font/malgun_boot.ttf");
                        sf::Text text2;
                        text2.setFont(font2); // Set the font
                        text2.setPosition(635, 270);
                        text2.setCharacterSize(50); // Set the character size
                        text2.setFillColor(sf::Color::White); // Set the text color
                        text2.setString("LINES"); // Set the string to display
                        text2.setStyle(sf::Text::Bold);
                        window.draw(text2);


                        sf::Font font3;
                        font3.loadFromFile("font/malgun_boot.ttf");
                        sf::Text text3;
                        text3.setFont(font3); // Set the font
                        text3.setPosition(660, 360);
                        text3.setCharacterSize(50); // Set the character size
                        text3.setFillColor(sf::Color::White); // Set the text color
                        text3.setString(to_string(line)); // Set the string to display
                        text3.setStyle(sf::Text::Bold);
                        window.draw(text3);



                        sf::Font font4;
                        font4.loadFromFile("font/malgun_boot.ttf");
                        sf::Text text4;
                        text4.setFont(font4); // Set the font
                        text4.setPosition(622, 485);
                        text4.setCharacterSize(50); // Set the character size
                        text4.setFillColor(sf::Color::White); // Set the text color
                        text4.setString("LEVELS"); // Set the string to display
                        text4.setStyle(sf::Text::Bold);
                        window.draw(text4);


                        sf::Font font5;
                        font5.loadFromFile("font/malgun_boot.ttf");
                        sf::Text text5;
                        text5.setFont(font5); // Set the font
                        text5.setPosition(670, 570);
                        text5.setCharacterSize(50); // Set the character size
                        text5.setFillColor(sf::Color::White); // Set the text color
                        text5.setString(to_string(level)); // Set the string to display
                        text5.setStyle(sf::Text::Bold);
                        window.draw(text5);
                    }

                    if (game_over != true)
                    {
                        for (int i = 0;i < 20;i++) {

                            for (int j = 0;j < 15;j++) {

                                if (gridArray[i][j] == 1) {

                                    square.setPosition(j * 35, i * 35);
                                    square.setFillColor(colors[colorOfGrid[i][j]]);
                                    square.setOutlineColor(Color::White);
                                    square.setOutlineThickness(1.0f);
                                    // square.setFillColor(sf::Color::Red);
                                    window.draw(square);
                                }
                                else if (gridArray[i][j] == 9) {
                                    sf::CircleShape circle(17);
                                    circle.setFillColor(colors[bombColor]);
                                    circle.setPosition(j * 35, i * 35);
                                    window.draw(circle);
                                }

                            }
                        }

                    }

                    //---The Window that now Contains the Frame is Displayed---//
                    window.display();

                    sleep(seconds(delayBetweenFrames));
                }
            
        }
    return 0;
}
void readFile() {
    ifstream file;
    int  num = 0;
    file.open("record.bin");
    for (int i = 0;i < 10;i++) {
        file.read((char*)&num, sizeof(num));
        scoreArray[i] = num;
    }
    file.close();
}
void writeFile(int num) {
    // to read file
    ofstream writeFile;
    int temp = 0,temp1=0;
    if (num > scoreArray[9])
    {
        scoreArray[9] = num;
    }
    cout << "here" << endl;

    for (int i = 0;i < 10;i++)
    {
        for (int j = 0;j < 10;j++)
        {
            if (scoreArray[i] > scoreArray[j])
            {
                temp1 = scoreArray[i];
                scoreArray[i] = scoreArray[j];
                scoreArray[j] = temp1;
            }
        }
    }
    writeFile.open("record.bin", ios::binary);


    if (!writeFile.is_open()) {
        cerr << "Failed to open files for reading/writing." << endl;
        return;
    }
    for (int i = 0;i < 10;i++) {
        int var = scoreArray[i];
        writeFile.write(reinterpret_cast<char*>(&var), sizeof(var));
    }
    cout << "There" << endl;

    writeFile.close();

}