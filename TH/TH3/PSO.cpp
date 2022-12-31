#include <bits/stdc++.h>

using namespace std;

//particle = 5;
//generation = 100;
//c1 = c2 = 1.5
//w = 0.4
// 3x + 2y + z + q = 34
// nghiem thuoc 0 25
class Particle 
{
	public:
		vector<double> position, velocity, bestPosition;
		double fitness, bestFitness;
		
		void Init(vector<double> pos, vector<double> vel, vector<double> bestPos, double pBest, double gBest) 
		{
			position = pos;
			velocity = vel;
			bestPosition = bestPos;
			fitness = pBest;
			bestFitness = gBest;
		}
		
		string toString() 
		{
			string s = "================\n";
			s += "Position: ";
			for (int i = 0; i < position.size(); ++i)	s += to_string(position[i]) + " ";
			s += "\nFitness = " + to_string(fitness);
			s += "\nVelocity: ";
			for (int i = 0; i < velocity.size(); ++i)	s += to_string(velocity[i]) + " ";
			s += "\nBestFitness = " + to_string(round(bestFitness));
			s += "\nBest Position: ";
			for (int i = 0; i < bestPosition.size(); ++i)	s += to_string(round(bestPosition[i])) + " ";
			s += "\n================\n";
			return s;
		}
};
double randomNumber() 
{
	return rand()/(float) RAND_MAX;
}
void randomVector(vector<double> &temp, double high, double low) 
{
	for (int i = 0; i < temp.size(); ++i) 
	{
		temp[i] = (high - low) * randomNumber() + low;
	}
}

double ObjectiveFunction(vector<double> x) 
{
	return abs(3.0 * round(x[0]) + 2.0 * round(x[1]) + round(x[2]) + round(x[3]) - 34);
}

int main() 
{
	srand((unsigned)time(nullptr));
	cout << "Bat dau thuat toan PSO \n";
	int numParticles = 5, numIterations = 100, iteration = 0, dim = 4;
	double w = 0.7, c1 = 2, c2 = 2, minX = 0.0, maxX = 25.0, r1, r2;
	double bestGlobalFitness = LLONG_MAX, curFitness;
	vector <Particle> swarm(numParticles);
	vector<double> bestGlobalPosition(dim);
	
	cout << "Giai phuong trinh 3x + 2y + z + q = 24\n";
	cout << "So ca the: " << numParticles << endl;
	cout << "So the he: " << numIterations << endl;
	cout << "He so Inertia: " << w << endl;
	cout << "Mien gia tri cua nghiem: (" << minX << ", " << maxX << ")\n";
	cout << "c1 = " << c1 << ", c2 = " << c2 << endl; 
	
	cout << "Khoi tao quan the (the he 1) voi cac gia tri ngau nhien!" << endl;;
	for (int i = 0; i < swarm.size(); ++i) 
	{
		vector<double> randomPos(dim), randomVel(dim);
		randomVector(randomPos, maxX, minX);
		curFitness = ObjectiveFunction(randomPos);
		randomVector(randomVel, maxX, -maxX);
		Particle p;
		p.Init(randomPos, randomVel, randomPos, curFitness, curFitness);
		swarm[i] = p;
		if(swarm[i].fitness < bestGlobalFitness) 
		{
			bestGlobalFitness = swarm[i].fitness;
			bestGlobalPosition = swarm[i].position;
		}
	}
	cout << "Khoi tao thanh cong !" << endl;
	cout << "BestFitness khoi tao = " << bestGlobalFitness << endl;
	cout << "Nghiem tot nhat !\n";
	for (int i = 0; i < bestGlobalPosition.size(); ++i) 
	{
		cout << "x" << i << " = " << to_string(round(bestGlobalPosition[i])) << " ";
	}
	cout << "\nPSO loop:\n";
	while(iteration < numIterations) 
	{
		++iteration;
		vector<double> newVel(dim), newPos(dim);
		for (int i = 0; i < swarm.size(); ++i) 
		{
			for (int j = 0; j < swarm[i].velocity.size(); ++j) 
			{
				r1 = randomNumber();
				r2 = randomNumber();
				newVel[j] = w * swarm[i].velocity[j] + c1 * r1 * (swarm[i].bestPosition[j] - swarm[i].position[j]) + c2 * r2 * (bestGlobalPosition[j] - swarm[i].position[j]);
				newVel[j] = max(-maxX, newVel[j]);
				newVel[j] = min(maxX, newVel[j]);
			}
			
			swarm[i].velocity = newVel;
			for (int j = 0; j < swarm[i].position.size(); ++j) 
			{
				newPos[j] = swarm[i].position[j] + newVel[j];
				newPos[j] = max(minX, newPos[j]);
				newPos[j] = min(maxX, newPos[j]);
			}
			swarm[i].position = newPos;
			curFitness = ObjectiveFunction(newPos);
			swarm[i].fitness = curFitness;
			if (curFitness < swarm[i].bestFitness) 
			{
				swarm[i].bestPosition = newPos;
				swarm[i].bestFitness = curFitness;
			}
			if(curFitness < bestGlobalFitness) 
			{
				bestGlobalFitness = curFitness;
				bestGlobalPosition = newPos;
			}
		}
		cout << "\nThe he " << iteration << endl;
		cout << swarm[0].toString() << endl;
		cin.get();
	}
}
