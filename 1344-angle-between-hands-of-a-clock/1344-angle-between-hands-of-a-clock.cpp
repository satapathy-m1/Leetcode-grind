class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minDeg = minutes * 6;
        if(hour == 12) hour = 0;
        double hrDeg = hour * 30 + (minDeg / 12);
        double mini = 360;
        if(hrDeg - minDeg >= 0) mini = min(mini, hrDeg - minDeg);
        else mini = min(mini, minDeg - hrDeg);

        return mini > 180 ? 360 - mini : mini;
    }
};