import pygame
import random
import os

pygame.mixer.init()
pygame.init()

white = (255, 255, 255)
yellow = (255, 225, 0)
red = (255,0, 0)
black = (0, 0, 0)
green = (0,255,0)
grey = (150,200,180)

screen_width = 900
screen_height = 600
gw = pygame.display.set_mode((screen_width, screen_height))

bgimg = pygame.image.load("homescreen.jpg")
bgimg = pygame.transform.scale(bgimg, (screen_width, screen_height)).convert_alpha()


pygame.display.set_caption("SnakesWithHarry")
pygame.display.update()
clock = pygame.time.Clock()
font = pygame.font.SysFont(None, 45)



def show_score(text, color, x, y):
    screen_text = font.render(text, True, color)
    gw.blit(screen_text, [x,y])


def plot_snake(gameWindow, color, snk_list, snake_size):
    for x,y in snk_list:
        pygame.draw.rect(gameWindow, color, [x, y, snake_size, snake_size])


def welcome():
    exit_game = False
    while not exit_game:
        gw.fill(black)
        gw.blit(bgimg, (0, 0))
        show_score(" The Game... ",red,350,430)
        show_score("Press SPACEBAR to start",red,250,470)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                exit_game = True
            
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE:
                    pygame.mixer.music.load('game_music.mp3')
                    pygame.mixer.music.play()
                    gameloop()
            
                    
        pygame.display.update()
        clock.tick(60)
            
def gameloop():

    exit_game = False
    game_over = False
    snake_x = 45
    snake_y = 55
    vx = 0
    vy = 0
    snk_list = []
    snk_length = 1

    food_x = random.randint(20, int(screen_width / 2))
    food_y = random.randint(20, int(screen_height / 2))
    score = 0
    speed = 5
    snake_size = 30
    fps = 60
    
    if not os.path.exists("highscore.txt"):
        with open ("highscore.txt","w") as f:
                f.write("0")
                
    with open ("highscore.txt","r") as f:
        highscore = f.read()
    
    
    while not exit_game:
        if game_over:
            with open ("highscore.txt","w") as f:
                f.write(str(highscore))
            gw.fill(black)

            show_score("  Naagin Khatam, Kahaani Khatam   Press Enter To Continue  ", red, 5, 250)
            show_score("                                               Zeher : " + str(score) , yellow, 10, 290)
            

            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    exit_game = True

                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_RETURN:
                        welcome()

        else:

            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    exit_game = True

                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_RIGHT:
                        vx = speed
                        vy = 0

                    if event.key == pygame.K_LEFT:
                        vx = -speed
                        vy = 0

                    if event.key == pygame.K_UP:
                        vx = 0
                        vy = -speed

                    if event.key == pygame.K_DOWN:
                        vx = 0
                        vy = speed
                    if event.key == pygame.K_q:
                        score += 20

            snake_x = snake_x + vx
            snake_y = snake_y + vy

            if abs(snake_x - food_x)<20 and abs(snake_y - food_y)<20:
                score +=10
                food_x = random.randint(20, int(screen_width / 2))
                food_y = random.randint(20, int(screen_height / 2))
                snk_length +=5
                if score > int(highscore):
                    highscore = score

            gw.fill(black)
            

            show_score("Score : " + str(score) + " HighScore : " + str(highscore), red, 5, 5)
            pygame.draw.rect(gw, yellow, [food_x, food_y, snake_size, snake_size])


            head = []
            head.append(snake_x)
            head.append(snake_y)
            snk_list.append(head)

            if len(snk_list)>snk_length:
                del snk_list[0]

            if head in snk_list[:-1]:
                pygame.mixer.music.load('boom.mp3')
                pygame.mixer.music.play()
                game_over = True

            if snake_x<0 or snake_x>screen_width or snake_y<0 or snake_y>screen_height:
                game_over = True
                pygame.mixer.music.load('boom.mp3')
                pygame.mixer.music.play()
            plot_snake(gw, red, snk_list, snake_size)
        pygame.display.update()
        clock.tick(fps)

    pygame.quit()
    quit()


pygame.mixer.music.load('home_music.mp3')
pygame.mixer.music.play()
welcome()



