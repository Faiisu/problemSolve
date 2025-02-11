    for(int i = 0; i < h ; i++){
        for(int j = 0 ; j < w; j++){
            if(cost[i+1][j+1] != INT_MAX)
                cout << cost[i+1][j+1] << " ";
            else cout << "X ";
        }
        cout << endl;
    }