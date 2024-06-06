/*
    This is the recursive way dor solving the problem 
*/

int recusrive(int day,int last, vector<vector<int>> &points){
    //base case 
    if(day == 0){
        int maxi =0;
        for(int task = 0 ; task< 3;task++){
            if(task!=last){
                maxi =  max(maxi,points[0][task]);
            }            
        }
        return maxi;
    }

    int maxi =0;
    for(int task = 0;task <3 ;task++){
        if(task!=last){
            int collectedPoints = points[day][task] + recusrive(day-1, task,points);
            maxi = max(maxi,collectedPoints);
        }
    }
    return maxi;

    
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    return recusrive(n-1, 3, points);
}

