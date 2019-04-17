#include<iostream>
using namespace std;

class BinaryHeap
{
	private:
	int mSize, cSize, *Arr;
	Arr= int[50];
	public:
	BinaryHeap()
	{
		mSize=50;
		cSize=0;
	}
	int left(int i){return ((2*i)+1);}
	int right(int i){return ((2*i)+2);}
	int parent(int i){return ((i-1)/2);}
	void insert(int data)
	{
		if(cSize==0)
		{
			cSize++;
			Arr[0]=data;
		}
		else if(cSize==mSize)
		{
			cout<<"can't insert anymore elements";
			return;
		}
		else
		{
			if(data<=Arr[0])
			{

				for(int i=cSize;i>0;i--)
				{
					Arr[cSize+1]=Arr[cSize];
				}
				Arr[0]=data;
			}
			else
			{
				Arr[cSize]=data;
				int l=cSize;
				while(Arr[parent(l)]>Arr[l] || parent(l)!=cSize/2)
				{
					int temp;
					temp = Arr[l];
					Arr[l] = Arr[parent(l)];
					Arr[parent(l)] = temp;
					l=parent(l);
				}
			}
			cSize++;
		}
	}
	int GetMin(){return Arr[0];}
	int extractMin()
	{
		if(cSize==0)
		{
			cout<<"it's an empty heap";
			return NULL;
		}
		else if(cSize == 1)
		{
			cSize--;
			return Arr[0];
		}
		else
		{
			int temp = Arr[0];
			for(int i=0;i<cSize;i++)
			{
				Arr[i]=Arr[i+1];
			}
			cSize--;
			return temp;
		}
	}
	void DecreaseKey(int i, int new_val)
	{
		Arr[i]=new_val;
		while( (Arr[parent(i)]>Arr[i] && i==left(parent(i))) || (Arr[parent(i)]<Arr[i] && i==right(parent(i))) || (i==0) )
		{
			temp=Arr[i];
			Arr[i]=Arr[parent(i)];
			Arr[parent(i)]=temp;
			i=parent(i);
		}
		return 0;
	}
	void display()
	{
		if(cSize==0)
		{
			cout<<"empty heap"<<endl;
			return;
		}
		for(int i=0;i<cSize;i++)
		{
			cout<<Arr[i]<<",";
		}
		cout<<endl;
	}
};

int main()
{
	BinaryHeap lol;
	lol.display();
	for(int i=0;i<10;i++)
	{
		lol.insert(i+1);
	}
	lol.insert(-3);
	lol.display();
	return 0;
}
