import pygame
from random import randint
pygame.init()

back = (255,255,0)
BLACK = (0,0,0)
LIGHT_BLUE = (200,200,255)

clock = pygame.time.Clock()
mw = pygame.display.set_mode((500,500))
mw.fill(back)


class TextArea():
    def __init__(self, x=0, y=0, width =10, height =10, color=None):
        self.rect = pygame.Rect(x, y, width, height)
        self.fill_color = color

    def set_text(self, text, fsize =12, text_color=BLACK):
        self.text = text
        self.image = pygame.font.Font(None, fsize).render(text,True, text_color)

    def draw(self, shift_x=0, shift_y=0):
        pygame.draw.rect(mw,self.fill_color,self.rect)
        mw.blit(self.image, (self.rect.x + shift_x,self.rect.y + shift_y))


quest_card = TextArea(120,100,290,70, LIGHT_BLUE)
quest_card.set_text("Питання",75)

ans_card = TextArea(120,240,290,70, LIGHT_BLUE)
ans_card.set_text("Відповідь",75)

num = randint (1,3)
if num == 1:
    quest_card.set_text('Що вивчаєш в Алгоритміку?',25)
if num ==2:
    quest_card.set_text('Якою мовою говорять у Франції?',25)
if num ==3:
    quest_card.set_text('Що росте на яблуні?',35)


num1 = randint (1,3)
if num1 ==1:
    ans_card.set_text('Python',35)
if num1 ==2:
    ans_card.set_text('Французька',35)
if num1 ==3:
    ans_card.set_text('Яблука',35)

while 1:
    pygame.display.update()
    quest_card.draw(10,10)
    ans_card.draw(10,10)
    clock.tick(40)


  