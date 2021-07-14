# Lab10: Prim's Algorithm(Minimal Spanning Tree)

### 1. Input data는 다음 그래프들을 사용할 것(Adjacency Matrix로 저장)

<div align = center>

![image](https://user-images.githubusercontent.com/24904962/124967218-214ad780-e05f-11eb-8999-6ae56d372614.png)


</div>

### 2. 참고

  1. main()

      - print weighted Graph()

      - call prim(A)  // Starting vertex A

      - 알고리즘 강의노트 참조

### 3. Output은 다음과 같다.(정점 A에서 시작)

  1. Weighted Graph를 다음과 같이 출력할 것

      |       |   A   |   B   |   C   |   D   |   E   |   F   |
      | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
      | **A** |   0   |   5   |  100  |  12   |  100  |  100  |
      | **B** |   5   |   0   |   6   |  10   |  24   |  100  |
      | **C** |  100  |   6   |   0   |  17   |  100  |  30   |
      | **D** |  12   |  10   |  17   |   0   |  20   |  100  |
      | **E** |  100  |  24   |  100  |  20   |   0   |  13   |
      | **F** |  100  |  100  |  30   |  100  |  13   |   0   |

  2. Minimal Spanning Tree (Greedy Algorithm)

      <pre>MST:  (A, B) ->  (B, C)  ->  (C, D)  ->  (D, E)  ->  (E, F)
      Weight: 61</pre>

  3. Revised Prim's Algorithm (A에서 시작, 모든 후보군 함께 고려함)

      <pre>MST:  (A, B) ->  (B, C)  ->  (B, D)  ->  (D, E)  ->  (E, F)
      Weight: 54</pre>

## Extra 5 Points (Kruskal's Algorithm)

### 1. 위 그래프를 데이터로 이용할 것(Adjacency list로 저장)

### 2. Sorting algorithm은 임의의 알고리즘 사용 가능

### 3. Kruskal's 알고리즘 (강의 노트 참조)

### 4. 실행 결과(Output)

**Original Data:**

  A 5 B,  B 6 C,  A 12 D, B 10 D, C 17 D

  B 24 E, D 20 E, C 30 F, E 13 F

**Sorted Data:**

  A 5 D,  B 6 C,  B 10 D, A 12 D, E 13 F,

  C 17 D, D 20 E, B 24 E, C 30 F

**Kruskal's MST:**

  1. Edge1: A 5 B

  2. Edge2: B 6 C
   
  3. Edge3: B 10 D
   
  4. Edge4: E 13 F
   
  5. Edge5: D 20 E

**Total Cost:  54**

---

### Compile

#### Lab 9-1

```cmd
> g++ -o Lab10-1 Lab10-1.cpp
```

#### Lab 9-2

```cmd
> g++ -o Lab9-2 Lab9-2.cpp
```