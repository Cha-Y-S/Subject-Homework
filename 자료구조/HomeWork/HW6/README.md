# HW6: Shortest Path

  1. Shortest Path Algorithm은 강의노트 알고리즘 참조

  2. 테스트 그래프는 다음 2개의 그래프를 이용하여 각각 출력할 것

### <<Correct Output은 다음과 같다>>

**테스트 그래프 1** (\*\* 시작 정점은 노드 '0'에서 시작함)

  1. Cost matrix 출력

      |       |   0   |   1   |   2   |   3   |   4   |   5   |   6   |
      | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
      |   0   |  100  |   2   |   4   |   5   |  100  |  100  |  100  |
      |   1   |  100  |  100  |  100  |   2   |   7   |  100  |  100  |
      |   2   |  100  |  100  |  100  |   1   |  100  |   4   |  100  |
      |   3   |  100  |   2   |   1   |  100  |   4   |   3   |  100  |
      |   4   |  100  |   7   |  100  |   4   |  100  |   1   |   5   |
      |   5   |  100  |  100  |   4   |   3   |   1   |  100  |   7   |
      |   6   |  100  |  100  |  100  |  100  |   7   |   5   |  100  |

  2. Shortest path distance

      Dist:&nbsp;&nbsp;&nbsp;&nbsp;0 2 4 5 100 100 100&nbsp;&nbsp;&nbsp;&nbsp;(Selected Node: 1)

      Dist:&nbsp;&nbsp;&nbsp;&nbsp;0 2 4 4 9 100 100&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(Selected Node: 2)

      Dist:&nbsp;&nbsp;&nbsp;&nbsp;0 2 4 4 9 8 100&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(Selected Node: 3)

      Dist:&nbsp;&nbsp;&nbsp;&nbsp;0 2 4 4 8 7 100&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(Selected Node: 5)

      Dist:&nbsp;&nbsp;&nbsp;&nbsp;0 2 4 4 8 7 14&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(Selected Node: 4)

      **Dist:&nbsp;&nbsp;&nbsp;0 2 4 4 8 7 13&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(Selected Node: 6)**

<br />

**테스트 그래프2** (\*\* 시작 정점은 노드 '4'에서 시작함)

  1. Cost matrix 출력

      |       |    0     |    1    |    2     |    3     |    4    |    5    |    6    |    7     |
      | :---: | :------: | :-----: | :------: | :------: | :-----: | :-----: | :-----: | :------: |
      |   0   | ***0***  |  10000  |  10000   |  10000   |  10000  |  10000  |  10000  |  10000   |
      |   1   | **300**  | ***0*** |  10000   |  10000   |  10000  |  10000  |  10000  |  10000   |
      |   2   | **1000** | **800** | ***0***  |  10000   |  10000  |  10000  |  10000  |  10000   |
      |   3   |  10000   |  10000  | **1200** | ***0***  |  10000  |  10000  |  10000  |  10000   |
      |   4   |  10000   |  10000  |  10000   | **1500** | ***0*** | **250** |  10000  |  10000   |
      |   5   |  10000   |  10000  |  10000   | **1000** |  10000  | ***0*** | **900** | **1400** |
      |   6   |  10000   |  10000  |  10000   |  10000   |  10000  |  10000  | ***0*** | **1000** |
      |   7   | **1700** |  10000  |  10000   |  10000   |  10000  |  10000  |  10000  | ***0***  |

  2. Shortest path distance

      Beginning Dist:&nbsp;&nbsp;&nbsp;&nbsp;10000 10000 10000 1500 0 250 10000 10000

      Select (5) dist:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;10000 10000 10000 1250 0 250 1150 1650

      Select (6) dist:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;10000 10000 10000 1250 0 250 1150 1650

      Select (3) dist:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;10000 10000 2450 1250 0 250 1150 1650

      Select (7) dist:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3350 10000 2450 1250 0 250 1150 1650

      Select (2) dist:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3350 3250 2450 1250 0 250 1150 1650

      Select (1) dist:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3350 3250 2450 1250 0 250 1150 1650

      **<u> Select (0) dist:&nbsp;&nbsp;&nbsp;&nbsp;3350 3250 2450 1250 0 250 1150 1650 </u>**

### Compile

```cmd
> g++ -o HW6 HW6.cpp MyGraph.hpp
```