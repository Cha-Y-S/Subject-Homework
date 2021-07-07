# Lab 9: Graph operations(DFS)

### 입력 그래프(Adjacency list로 표현할 것)

  - 참고
    
    ```cpp
    class Node {private: int data; Node *link;}
    ```
  <div align = center>

  ![image](https://user-images.githubusercontent.com/24904962/124496640-a4b4c080-ddf4-11eb-92f4-f5fc6265925b.png)

  </div>

  ```cpp
  void main() {
    initialize VISITED[i] = false;
    get INPUT data;   // graph[i] => head nodes
    print_input data; // print stored adjacency list
    dfs(v0);          // starting vertex 0
  } // end of main

  void dfs(V) {  // 강의노트 알고리즘 참조
    visited[V] = true;    print V;
    for(next = graph[v]; next != NULL; next = next->link)
      if(!visited[next->data]) DFS(next->data);
  }
  ```

### Output (Data 출력 및 DFS 결과)

  1. Graph Data:

    V0:   1 -> 2
    V1:   0 -> 2 -> 3
    V2:   0 -> 1 -> 5
    V3:   1 -> 4 -> 5
    V4:   3 -> 5
    V5:   2 -> 3 -> 4

  2. Depth First Search Output(starting from v0)

  <div align = center>

  V0 -> V1 -> V2 -> V5 -> V3 -> V4

  </div>

## Extra Point: Graph operations - (BFS)

  - 그래프 데이터는 다음 Adjacency Matrix를 사용할 것

### Output (Data 출력 및 BFS 탐색의 결과)


<div align = center>
<table>
  <caption> Adjacent Matrix </cation>
  <tbody>
    <tr>
      <th align = center> </th>
      <th align = center>v0</th>
      <th align = center>v1</th>
      <th align = center>v2</th>
      <th align = center>v3</th>
      <th align = center>v4</th>
      <th align = center>v5</th>
    </tr>
    <tr>
      <td align = center>v0</td>
      <td align = center>0</td>
      <td align = center>0</td>
      <td align = center>0</td>
      <td align = center>0</td>
      <td align = center>1</td>
      <td align = center>1</td>
    </tr>
    <tr>
      <td align = center>v1</td>
      <td align = center>0</td>
      <td align = center>0</td>
      <td align = center>1</td>
      <td align = center>1</td>
      <td align = center>0</td>
      <td align = center>1</td>
    </tr>
    <tr>
      <td align = center>v2</td>
      <td align = center>0</td>
      <td align = center>1</td>
      <td align = center>0</td>
      <td align = center>1</td>
      <td align = center>1</td>
      <td align = center>0</td>
    </tr>
    <tr>
      <td align = center>v3</td>
      <td align = center>0</td>
      <td align = center>1</td>
      <td align = center>1</td>
      <td align = center>0</td>
      <td align = center>0</td>
      <td align = center>0</td>
    </tr>
    <tr>
      <td align = center>v4</td>
      <td align = center>1</td>
      <td align = center>0</td>
      <td align = center>1</td>
      <td align = center>0</td>
      <td align = center>0</td>
      <td align = center>1</td>
    </tr>
    <tr>
      <td align = center>v5</td>
      <td align = center>1</td>
      <td align = center>1</td>
      <td align = center>0</td>
      <td align = center>0</td>
      <td align = center>1</td>
      <td align = center>0</td>
    </tr>
  </tbody>
  <tfoot>
    <tr>
      <td colspan = "7" align = center>Breadth First Search(BFS) : v0 v4 v5 v2 v1 v3</td>
    </tr>
  </tfoot>
</table>
</div>

  - 참고

    ```cpp
    int graph[max][max] = {{0,0,0,0,1,1}, {0,0,1,1,0,1}, ...}
    int front = 0, rear = 0, queue[5];
    char visited[max];

    main(){
      initializeQ();                              // Queue 초기화 front = rear = 0;
      print Adjacent Matrix;                      // 그래프 데이터 출력
      for(i = 0; i < max; i++) visited[i] = 'f';  // 방문 검사 위한 배열을 초기화
      bfs(v);
    }

    bfs(){
      addq(v);    // v->start node;
      v = deque();
      while(!Qempty){
        for(인접된 모든 노드 w에 대해서)
          if(not visited) && (g[v][w] != 0){
            addq(w);  visited[w] = 't'; cout << " " << w;
          }
        v = deletequeue();
      }
    }
    ```