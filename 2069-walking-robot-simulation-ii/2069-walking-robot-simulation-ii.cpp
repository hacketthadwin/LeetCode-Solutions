class Robot {
public:
vector<int>curr_pos;
string curr_dir;
int w,h;
    Robot(int width, int height) {
        w=width,h=height;
        curr_pos = {0,0};
        curr_dir ="East";
    }
    
    void step(int num) {
        //this optimisation is required otherwise it gave tle
        int cycle = 2*(w + h) - 4;
        num %= cycle;
        if(num == 0) num = cycle;
        while(num>0)
        {
            if(curr_dir=="East")
            {
                int pos_steps=min(num,w-1-curr_pos[1]);
                int max_steps_possible=w-1-curr_pos[1];
                curr_pos[1]+=pos_steps;
                if(num>max_steps_possible)
                {
                    curr_dir="North";
                }
                num-=pos_steps;
            }
            else if(curr_dir=="North")
            {
                int pos_steps=min(num,h-1-curr_pos[0]);
                int max_steps_possible=h-1-curr_pos[0];
                curr_pos[0]+=pos_steps;
                if(num>max_steps_possible)
                {
                    curr_dir="West";
                }
                num-=pos_steps;
            }
            else if(curr_dir=="West")
            {
                int pos_steps=min(num,curr_pos[1]);
                int max_steps_possible=curr_pos[1];
                curr_pos[1]-=pos_steps;
                if(num>max_steps_possible)
                {
                    curr_dir="South";
                }
                num-=pos_steps;
            }
            else
            {
                int pos_steps=min(num,curr_pos[0]);
                int max_steps_possible=curr_pos[0];
                curr_pos[0]-=pos_steps;
                if(num>max_steps_possible)
                {
                    curr_dir="East";
                }
                num-=pos_steps;
            }
        }
    }
    
    vector<int> getPos() {
        vector<int>real_pos=curr_pos;
        reverse(real_pos.begin(),real_pos.end());
        return real_pos;
    }
    
    string getDir() {
        return curr_dir;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */