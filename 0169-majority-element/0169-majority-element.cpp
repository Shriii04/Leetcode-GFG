int n=arr.size()/2;
    vector<int>ans;
    map<int,int>m;
    for(auto i:arr){
        m[i]++;
    }
    for(auto i:m){
        if(i.second>n){
            ans.push_back(i.first);
        }
    }
    return ans;



     

        
       
   

           
          
           
  
                
  
           
           
               





