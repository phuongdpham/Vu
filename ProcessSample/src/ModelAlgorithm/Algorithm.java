/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ModelAlgorithm;

/**
 *
 * @author MrVu
 */
public class Algorithm {
    public Integer[][] data; 
    public int Count;
    
    // QUTDQ
    private boolean[] kt;
    
    public Algorithm() {
        Count = 0;
    }
    
    public Algorithm(int count, Integer[][] data) {
        Count = count;
        this.data = data;
    }

    public void setInput(Integer[][] data) {
        this.data = data;
    }

    public void processFIFO() {
        int timeOut = 0;
        
        for (int i = 0; i < Count; i++) {
            if (timeOut < data[i][2]) {
                timeOut = data[i][2];
            }
            
            timeOut += data[i][1];
            data[i][3] = timeOut;
            data[i][4] = data[i][3] - data[i][1] - data[i][2];
        }
    }
    
    public void processQUTDQ() {
        int maxTime = 0;
        kt = new boolean[Count];
        
        for (int i = 0; i < Count; i++) {
            maxTime += data[i][1];
            kt[i] = true;
        }
        
        int ut, i, j, k;
        
        for (i = 0; i < maxTime; i++) {
            for (k = 0; k < Count; k++) {
                if (kt[k] && (i >= data[k][2])) {
                    ut = data[k][3];
                    int dem = k;
                    for (j = 1; j < Count; j++) {
                        if ((data[j][2] <= i) && kt[j]) {
                            if (data[j][3] > ut) {
                                ut = data[j][3];
                                dem = j;
                            }
                        }
                    }
                    kt[dem] = false;
                    i += data[dem][1];
                    data[dem][4] = i;
                    data[dem][5] = data[dem][4] - data[dem][2] - data[dem][1];
                    i--;
                    k = Count;
                }
            }
        }
    }
}
