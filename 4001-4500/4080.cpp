class BusBooking {
public:
    int k;
    vector<int> seatA;
    vector<int> seatB;
    vector<int> seatC;
    vector<int> seatD;
    int totalTime = 0;
    int minTime = 0;
    BusBooking(int n) {
        k = n;
        seatA.assign(k + 1, 0);
        seatB.assign(k + 1, 0);
        seatC.assign(k + 1, 0);
        seatD.assign(k + 1, 0);
    }
    void toggle(string seat) {
        char p = seat[0];
        string t = "";
        for (int i = 1; i <= seat.size(); i++) {
            t += seat[i];
        }
        int x = stoi(t);

        // Unbooking
        if (seatB[x] && p == 'B') {
            totalTime -= seatB[x];
            seatB[x] = 0;
            minTime -= 1;
            return;
        }
        if (seatA[x] && p == 'A') {
            totalTime -= seatA[x];
            minTime -= 1;
            seatA[x] = 0;
            return;
        }
        if (seatC[x] && p == 'C') {
            totalTime -= seatC[x];
            minTime -= 1;
            seatC[x] = 0;
            return;
        }
        if (seatD[x] && p == 'D') {
            totalTime -= seatD[x];
            minTime -= 1;
            seatD[x] = 0;
            return;
        }
        // Booking
        if (!seatB[x] && p == 'B') {
            totalTime += 1;
            seatB[x] = 1;
            minTime += 1;

            return;
        }
        if (!seatC[x] && p == 'C') {
            totalTime += 1;
            seatC[x] = 1;
            minTime += 1;
            return;
        }
        if (!seatA[x] && p == 'A' && !seatB[x]) {
            totalTime += 1;
            seatA[x] = 1;
            minTime += 1;
            return;
        }
        if (!seatD[x] && p == 'D' && !seatC[x]) {
            totalTime += 1;
            minTime += 1;
            seatD[x] = 1;
            return;
        }
        if (seatB[x] && p == 'A') {
            totalTime += 3;
            minTime += 1;
            seatA[x] = 3;
            return;
        }
        if (seatC[x] && p == 'D') {
            totalTime += 3;
            minTime += 1;
            seatD[x] = 3;
            return;
        }

        return;
    }

    int getTotalTime() { return totalTime; }

    int getMinTime() { return minTime; }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */
