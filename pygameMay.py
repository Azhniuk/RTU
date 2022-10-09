import pygame, sys
pygame.init()

# set up variables for the screen size in pixels
size = width, height = 640,480

screen = pygame.display.set_mode(size)

clock = pygame.time.Clock()

shape_position = (width / 2, height / 2)
shape_size = (100, 100)

shape_rect = pygame.Rect(shape_position, shape_size)

shape_color = (142, 58, 60)
line_color = (51, 116, 48)
circle_color = (143, 122, 59)

circle_pos = (50,50)

while True:
    clock.tick(60)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
        if event.type == pygame.MOUSEBUTTONDOWN:
            if event.button == pygame.BUTTON_LEFT:
                shape_rect.center = event.pos
            elif event.button == pygame.BUTTON_RIGHT:
                circle_pos = event.pos

       
    screen.fill((50,50,100))
    screen.fill(shape_color, rect=shape_rect)

    pygame.draw.circle(screen, circle_color, circle_pos, 25)
    pygame.draw.line(screen, line_color, circle_pos, shape_rect.center, 4)
  
    pygame.display.flip()
