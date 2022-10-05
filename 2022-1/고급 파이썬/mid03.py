class calcAvg:
  def read(self):
    f = open('/content/csvtest.txt', 'r')
    self.mylist = list(map(int, f.read().split(',')))
    f.close
  def avg(self):
    return sum(self.mylist) / len(self.mylist)
c = calcAvg()
c.read()
print(c.avg())
