from random import randrange
class Game():
	gas=[]
	gax=[]
	path=[]
	innerx=[]
	innery=[]
	dic={1:[0,0],2:[1,0],3:[2,0],4:[0,1],5:[1,1],6:[2,1],7:[0,2],8:[1,2],9:[2,2]}
	defaultx=0
	defaulty=0
	clock=[0,0]
	defa=0
	table=[]
	control=False
	winner=False
	def __init__(self,x):
		if x==0:self.defaultx,self.defaulty=0,0
		else:
			self.defaultx,self.defaulty=self.dic[x]
		self.defa=x
	def createtable(self):
		for i in range(3):
			self.table.append([ ])
			for a in range(3):
				self.table[i].append(' ')
	def isempty(self):
		if self.table[self.defaulty][self.defaultx]!=' ':self.control=True

	def isemptycomp(self):		
		if self.table[self.defaulty][self.defaultx]!=' ':return False
		else: return True
	def movex(self):
		self.isempty()
		self.table[self.defaulty][self.defaultx]='X'
		self.clock[0]+=1
		self.path.append(self.defa)
		self.innerx.append(self.defa)
	def movey(self):
		self.isempty()
		self.table[self.defaulty][self.defaultx]='O'
		self.clock[1]+=1
		self.path.append(self.defa)
		self.innery.append(self.defa)
	def quit(self):
		if self.clock==[5,4]: self.control=True
		self.winner_()
	def comtowin(self):	
		f__=open("pathes","r")
		self.gas=f__.readlines()
		for i in range(len(self.gas)):
			self.gas[i]=self.gas[i][:-1].split()
			self.gas[i]=map(int,self.gas[i])
		f__.close()
		fq_=open("innerx","r")
		self.gax=fq_.readlines()
		for i in range(len(self.gax)):
			self.gax[i]=self.gax[i][:-1].split()
			self.gax[i]=map(int,self.gax[i])
		fq_.close()
	def computer(self):
		possible=[]
		array=[]
		ttt=False
		x=False
		self.comtowin()
		while not x:		
			a=randrange(1,9,1)
			for t in self.gax:
				for i in range(len(self.innerx)):
					if self.innerx[i]==t[i]:ttt=True;continue
					else: ttt=False; break
				if ttt:
					aa=self.gas[self.gax.index(t)]
					tx=aa[aa.index(self.innerx[-1])+1]
					self.defaultx,self.defaulty=self.dic[tx]
					x=self.isemptycomp()
					if x: return
				 
			if a in array: continue
			array.append(a)
			self.defaultx,self.defaulty=self.dic[a]
			x=self.isemptycomp()
		array=[]
		self.defa=a	

	def winner_(self):
		if self.table[0][0]==self.table[0][1] and self.table[0][1]==self.table[0][2] and self.table[0][0]!=' ' :
			self.winner=True
			return self.table[0][0]
		if self.table[1][0]==self.table[1][1] and self.table[1][1]==self.table[1][2] and self.table[1][0]!=' ' : 
			self.winner=True
			return self.table[1][0]
		if self.table[2][0]==self.table[2][1] and self.table[2][1]==self.table[2][2] and self.table[2][0]!=' ' : 
			self.winner=True
			return self.table[2][0]
		if self.table[0][0]==self.table[1][0] and self.table[1][0]==self.table[2][0] and self.table[0][0]!=' ' : 
			self.winner=True
			return self.table[0][0]
		if self.table[0][1]==self.table[1][1] and self.table[1][1]==self.table[2][1] and self.table[0][1]!=' ' : 
			self.winner=True
			return self.table[0][1]
		if self.table[0][2]==self.table[1][2] and self.table[1][2]==self.table[2][2] and self.table[0][2]!=' ' : 
			self.winner=True
			return self.table[0][2]
		if self.table[0][0]==self.table[1][1] and self.table[1][1]==self.table[2][2] and self.table[0][0]!=' ' : 
			self.winner=True
			return self.table[0][0]
		if self.table[0][2]==self.table[1][1] and self.table[1][1]==self.table[2][0] and self.table[0][2]!=' ' : 
			self.winner=True
			return self.table[1][1]
		return 'this is a tie :('

'''def againstcomp():
	xxclock_=0
	a=Game(0)
	while not a.control and not a.winner:
		if xxclock_==0:a.createtable();xxclock_+=1;continue
		if xxclock_%2==1:
			inp=input()
			a=Game(inp)
			a.movex()
		else: a.computer();a.movey();print "\n"
		xxclock_+=1
		for i in range(3):
			print a.table[i]
		a.quit()
	if a.winner:
		print "%s is the winner!"%(a.winner_())
	else: print a.winner_()
	
	print a.path,"path"
	print a.innerx,"x"
	print a.innery,"y"
	if a.winner_()=='O':
		f_=open("pathes","a+")
		fq=open("innerx","a+")
		a.path=map(str,a.path)
		a.innerx=map(str,a.innerx)
		f_.write(' '.join(a.path))
		f_.write("\n")
		fq.write(' '.join(a.innerx))
		fq.write("\n")
	a.comtowin()
'''
def _2player():
	xxclock_=0
	a=Game(0)
	while not a.control and not a.winner:
		inp=input()
		a= Game(inp)
		if xxclock_==0:a.createtable()
		if xxclock_%2==0: a.movex()
		else: a.movey()
		xxclock_+=1
		for i in range(3):
			print a.table[i]
		a.quit()
	if a.winner:
		print "%s is the winner!"%(a.winner_())
	else: print a.winner_(),




















