class selfDT{
    public:
    int dis; //distance
    int x; //X-cordinate
    int y; //Y-cordinate

    selfDT(int dis, int x,int y)
    {
        this->dis=dis;
        this->x=x;
        this->y=y;
    }
};

class cmp{
    public:
    bool operator()(selfDT obj1, selfDT obj2)
    {
        //heapsort base on dis
        //maxHeap
        return obj1.dis<obj2.dis;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        int n=points.size();
        //maxHeap with always closest K points
        priority_queue<selfDT,vector<selfDT>,cmp>maxHeap;

        for(int i=0;i<n;i++)
        {
            int x=points[i][0];
            int y=points[i][1];

            int dis=x*x + y*y;//No sqrt because dis is used only for comparing
            // selfDT temp(dis,x,y);
            // pq.push(temp);
            //Alternatively we can do by this too
            // pq.push({dis,x,y});

            if(maxHeap.size()==k)
            {
                if(dis<maxHeap.top().dis)
                {
                    maxHeap.pop();
                    maxHeap.push({dis,x,y});
                }
            }
            else
            {
                maxHeap.push({dis,x,y});
            }
        }

        vector<vector<int>>closestKPoints;
        while(!maxHeap.empty())
        {
            auto temp=maxHeap.top();
            maxHeap.pop();

            int x=temp.x;
            int y=temp.y;

            closestKPoints.push_back({x,y});  
        }

        return closestKPoints;



        
        
    }
};