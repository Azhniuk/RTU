class Car(object):
  def start (self):
    print("Brmbrmbrmbrmbrm!")
  def stop (self):
    print("Stoppp!") 
  def init(self,d1,d2,d3):
   self.model=d1
   self.name=d2
   self.year=d3
  print("my cars:")
mycar1=Car("audi", "a8", 2010)
print(mycar1.model, mycar1.name, mycar1.year)
mycar2=Car("bmw", "m20", 2015)
print(mycar2.model, mycar2.name, mycar2.year)
Car.start()
car1 = Car()
car1.stop()