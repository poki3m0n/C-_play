#include <string>
#include <vector>
#include <sstream>  
#include <iomanip>      
#include <queue>
//function to check if the adjacent vertices are inside the maze
bool isInsideGrid(int i, int j) 
{ 
    return (i >= 0 && i < COL && j >= 0 && j < ROW); 
}
//Function to read the maze and add the weighted edges
void readmaze(Graph<WeightedVertex> G)
{
    WeightedVertex ob;
    multimap <unsigned,unsigned> grid= G.getEdges();
    unsigned x,y;
    vector<int>::iterator lower,upper; 
    cin>>x>>y;
    vector <vector<WeightedVertex>> tmp;
    unsigned p;
    tmp.resize(x,vector<WeightedVertex>(y));
    for (unsigned i = 0; i < x; i++)
    {
        for (unsigned j = 0; j < y; j++)
        {   
            
            cin >> p;
            ob.updateWeight(((i*y)+j),p);
            tmp[i][j]=ob;
            G.add(tmp[i][j],tmp[i-1][j]);
            G.add(tmp[i][j],tmp[i][j-1]);
            G.add(tmp[i][j],tmp[i][j+1]);
            G.add(tmp[i][j],tmp[i+1][j]);
        }
        
    }
     for (unsigned i = 0; i < x; i++)
    {
        for (unsigned j = 0; j < y; j++)
        {   if((i-1)>=0)
            {
            G.add(tmp[i][j],tmp[i-1][j]);
            }
            if((j-1)>=0)
            {
            G.add(tmp[i][j],tmp[i][j-1]);
            }
            if((j+1)<=y)
            {
            G.add(tmp[i][j],tmp[i][j+1]);
            }
            if((i+1)<=x)
            {
            G.add(tmp[i][j],tmp[i+1][j]);
            }
        }
    }
    

}



//Function that performs the dijkstra's algorithm on the graph
map<WeightedVertex,int> getSSSP( Graph<WeightedVertex> G , const WeightedVertex src )
{
    priority_queue < WeightedVertex , vector < WeightedVertex > , greater < WeightedVertex > > pq;
    set < WeightedVertex > temp = G.getVertices(); 
    multimap <unsigned,unsigned> grid= G.getEdges();
    vector < vector <unsigned> > dist[temp.size()];
    vector < bool > sptSet;
    pq.push(temp[0]);
    for (int i = 0; i < temp.size(); i++) 
       { dist[i] = INT_MAX;
        sptSet[i] = false; 
       }

    dist[src] = 0; 

    int dx[] = {-1, 0, 1, 0}; 
    int dy[] = {0, 1, 0, -1}; 

    while(!pq.empty())
    {
        int min=INT_MAX;
        WeightedVertex top = pq.top();
        pq.pop();
        for (int i = 0; i < 4; i++) 
        { 
            int x = top.x + dx[i]; 
            int y = top.y + dy[i]; 
  
            
            if (!isInsideGrid(x, y)) 
                continue; 
  
            if (dist[x][y] > dist[top.x][top.y] + grid[x][y]) 
            { 
                
                dist[x][y] = dist[top.x][top.y] + grid[x][y]; 
                pq.push(WeightedVertex(x, y, dist[x][y])); 
            }
       
	    }
    }  
}