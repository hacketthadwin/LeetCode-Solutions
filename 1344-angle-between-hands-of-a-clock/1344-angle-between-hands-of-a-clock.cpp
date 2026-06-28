class Solution {
public:
    double angleClock(int hour, int minutes) {
        //nice nice...so basically i also need to consider the deflection of hour hand after each minute..so basically 360/12..is the angle between each hour..and that too is now more deflected as ((360/12)/60)*minute
        //but also keep in mind the position from where this starts..i.e. ((360/12)*hour + ((360/12)/60)*minute) is the position of hour hand and (360/60)*minute is position of minute hand...and at last...the difference i will get is measured as 2 things...x and 360-x...and whichever is lower will be returned simply

        double angle_hr=(((double)(30)*hour)+((double)0.5*minutes));
        // angle_hr=min(angle_hr,abs(360-angle_hr));
        double angle_min=(6*minutes);
        // angle_min=min(angle_min,360-angle_min);

        double x=abs(angle_hr-angle_min);
        return min(x,360-x);
    }
};