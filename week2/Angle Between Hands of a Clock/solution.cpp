class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = (hour * 30.0) + (0.5 * minutes);
        double m = minutes * 6;
        
        
        double angle = abs(h - m);
        
        if( angle > 180 ) {
            return 360 - angle;
        }
        return angle;
    }
};