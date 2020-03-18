// void readMaze(Graph<WeightedVertex> G), int arr[][], int row, int col {
//     for(int i = 0; i<row; i<col; i++) {
//         for(int j = 0; j<col; j++) {
            
//             WeightedVertex v(getId(i, j, row, col));

//             if(isIndexValid(i-1, j, row, col)) {
//                 WeightedVertex v1(getId(i-1, j, row, col));
//                 G.add(v, v1);
//             }

//             if(isIndexValid(i+1, j, row, col)) {
//                 WeightedVertex v1(getId(i+1, j, row, col));
//                 G.add(v, v1);
//             }

//             if(isIndexValid(i, j-1, row, col)) {
//                 WeightedVertex v1(getId(i, j-1, row, col));
//                 G.add(v, v1);
//             }

//             if(isIndexValid(i, j+1, row, col)) {
//                 WeightedVertex v1(getId(i, j+1, row, col));
//                 G.add(v, v1);
//             }

//         }
//     }
// }

// map<WeightedVertex,int> getSSSP(Grpah g, set<WeightedVertex> v) {
//     // find shortest path


// }

// int minDistance(map<WeightedVertex, int> distanceMap, bool sptSet[]) 
// { 

//     int min = INT_MAX;
//     int minIndex; 

//     int i = 0
//     for (itr = v.begin(); itr != v.end(); ++itr) { 
//         if(sptSet[i] == false && *itr.IdWeight <= min) {
//             min = *itr.IdWeight;
//             min_index = i;
//             i++;
//         }
//     } 
//     return minIndex; 
// } 

// bool isIndexValid(int i, int j, int iMax, jMax) {
//     return (i >= 0 && i<iMax) && (j >= 0 && j<jMax);
// }

// int getId(int i, int j, int iMax, int jMax) {
//     return jMax * i + j;
// }

// pair<int, int> getRowCol(int id, int colMax) {
//     int row = id/colMax;
//     int col = id%colMax;
//     return make_pair(row, col);
// }