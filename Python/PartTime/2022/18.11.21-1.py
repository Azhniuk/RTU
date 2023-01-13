class Car(a):

 model = "Toyota"
 year=2018
 pwr=240
 mod=20

 def stop(self, a):
    print(a+self.pwr)

 def start(self):
     print("поїхали!")
 def hello(self):
     print("hello", self.mod)
 



car=Car()
car.start()
car.hello()
car.stop(12)


