class Team:
	name = ""
	fixt = []
	points = 0
	scored_goal = 0
	conceded_goal = 0
	played_match = 0
	def __init__(self,s = ""):
		self.name = s
		self.points = 0
		self.scored_goal = 0
		self.conceded_goal = 0
		self.played_match = 0
		self.fixt = []
	def print_(self):
		print('{0:30} | {1:3d} | {2:3d} | {3:3d} | {4:3d} | {5:3d} |'.format(self.name,self.played_match,self.scored_goal,self.conceded_goal,self.scored_goal-self.conceded_goal,self.points))

class Match:
	class score:
		HomeScore = 0
		AwayScore = 0
		def __init__(self,Hs = -1,As = -1):
			self.HomeScore = Hs
			self.AwayScore = As
	MatchsbyCode = {}
	code = 1000
	def __init__(self, ht = [], at = [],sc = score()):
		self.Home = ht
		self.Away = at
		self.Score = sc
		self.matchcode = str(Match.code)
		Match.code += 1
		Match.MatchsbyCode[self.matchcode] = [self]
	def setscore(self,Hs = -1,As = -1):
			self.HomeScore = Hs
			self.AwayScore = As
			self.Home[0].scored_goal += Hs
			self.Home[0].conceded_goal += As
			self.Away[0].scored_goal += As
			self.Away[0].conceded_goal += Hs
			self.Home[0].played_match +=1
			self.Away[0].played_match +=1
			if Hs == As:
				self.Home[0].points +=1
				self.Away[0].points +=1
			elif Hs > As:
				self.Home[0].points +=3
			else:
				self.Away[0].points +=3
	def print_(self):
		if self.Score.HomeScore == -1:
			print(self.Home[0].name," - ",self.Away[0].name)
		else:
			print(self.Home[0].name,self.Score.HomeScore,"-",self.Score.AwayScore,self.Away[0].name)


class Week:
	WeekNum = 0
	Matches = []
	def __init__(self,wn = 0):
		self.WeekNum = wn
		self.Matches = []
	def getMatch(self,m):
		self.Matches.append(m)
	def getscores(self):
		for i in self.Matches:
			if i[0].Home[0].name == "by":
				i[0].setscore(0,3)
				continue
			if i[0].Away[0].name == "by":
				i[0].setscore(3,0)
				continue
			print("Score of the match: ",)
			i[0].print_()
			a,b = [int(x) for x in input().split()]
			i[0].setscore(a,b)
	def print_(self):
		for i in self.Matches:
			i[0].print_()
			

class League:
	def __init__(self,name = ""):
		if not name:
			raise RuntimeError('You can\'t create a League without a name!')
		else:
			self.Leaguename = name
			self.Teams = []
			self.Weeks = []

	def getTeams(self,isfile):
		if self.Teams:
			raise RuntimeError("Teams were added already!!") 
		if isfile:
			sr = input("please give the name of file includes teams: ")
			self.getTeamsfromFile(sr)
		else:
			self.getTeamsfromKeyboard()

	def getTeamsfromKeyboard(self):
		while True:
			sr = input()
			if sr:
				self.Teams.append([Team(sr)])
			else:
				return

	def getTeamsfromFile(self,filename = ""):
		if not filename:
			raise RuntimeError("please add a filename to read the teams!")
		if type(filename) is not str:
			raise RuntimeError("please add a valid filename!")
		with open(filename) as f:
			for line in f:
				self.Teams.append([Team(line)])

	def printLeague(self):
		print(self.Leaguename)
		for teams in self.Teams:
			teams[0].print_()

	def CreateFixt(self):
		n = len(self.Teams)
		if n%2==1:
			self.Teams.append([Team("by")])
			n+=1
		A = []
		B = []
		for i in range(int(n/2)):
			A.append(i)
			B.append(n-i-1)

		for round in range(n-1):
			self.Weeks.append(Week(round+1))
			for index in range(int(n/2)):
				self.CreateMatch(A[index],B[index])
			self.Swap(A,B,round,n-1)

	def CreateMatch(self,a,b):
		min_ = min(a,b)
		max_ = max(a,b)
		match = [Match(self.Teams[min_],self.Teams[max_])]
		if(self.Teams[min_][0].name != "by"):
			self.Teams[min_][0].fixt.append(match)
		else:
			self.Teams[min_][0].fixt.append(self.Teams[max_][0].name)
		
		if(self.Teams[max_][0].name != "by"):
			self.Teams[max_][0].fixt.append(match)
		else:
			self.Teams[max_][0].fixt.append(self.Teams[min_][0].name)

		self.Weeks[-1].Matches.append(match)

	def Swap(self,A,B,round,N):
		prevLast = B[int((N-1)/2)]
		x = ""
		if round%2 == 0:
			x += str(N)
			x += ','
			x += str(prevLast)
		else:
			x += str(prevLast)
			x += ','
			x += str(N) 
		for i in range(int((N+1)/2)):
			if A[i] != N:
				x += ','
				x += str(A[i])
			if B[i] != prevLast and B[i] != N:
				x += ','
				x += str(B[i])
		x = [int(q) for q in x.split(',')]
		if(N>2):
			x[2],x[-2] = x[-2],x[2]
			x[3],x[-1] = x[-1],x[3]
		i = 0
		while i < N+1:
			A[int(i/2)] = x[i]
			B[int(i/2)] = x[i+1]
			i+=2
	def printWeeks(self):
		for i in self.Weeks:
			for j in i.Matches:
				j[0].print_()
			print()
	def printFixtofTeams(self):
		for i in self.Teams:
			if i[0].name!="by":
				print(i[0].name, "::::")
				for j in i[0].fixt:
					j[0].print_()
	def sortLeague(self):
		flag = True
		while flag:
			flag = False
			size = len(self.Teams)
			for i in range(size-1):
				if self.Teams[i][0].points < self.Teams[i+1][0].points:
					self.Teams[i],self.Teams[i+1]= self.Teams[i+1],self.Teams[i]
					flag = True
	def getscoreoftheweek(self,wn = -1):
		if wn == -1:
			raise RuntimeError ("Which week ?")
		for i in self.Weeks:
			if i.WeekNum == wn:
				i.getscores()
	def print_(self):
		print('{0:31} {1:5} {2:5} {3:5} {4:5} {5:5}'.format( self.Leaguename,"game","scg","cong","avg","points"))
		for i in self.Teams:
			if i[0].name == "by":
				continue
			i[0].print_()
	def printbycodes(self):
		first = 1000
		last = 1000+len(self.Weeks)*len(self.Weeks[0].Matches)
		print("it is coming wait for it...")
		for i in range(first,last):
			print(i),
			Match.MatchsbyCode[str(i)][0].print_()
	def getscorebycode(self,Hs ,As ,cd):
		Match.MatchsbyCode[str(cd)][0].setscore(Hs,As)
	



def test():
	a = League("L1")
	a.getTeams(0)
	a.CreateFixt()
	a.printFixtofTeams()
	a.printbycodes()
	b = a.Weeks[-1].WeekNum
	c = input("kod ver: ")
	x,y = [int(c) for c in input("skor gir: ").split()]
	a.getscorebycode(x,y,c)
	a.printbycodes()
	a.sortLeague()
	a.print_()

test()