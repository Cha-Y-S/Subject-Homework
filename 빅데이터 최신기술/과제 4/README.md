# Word Count

  위키피디아 문장 데이터 셋<https://www.kaggle.com/mikeortman/wikipedia-sentences>

  ### 데이터셋에서 가장 많이 등장한 단어 1000개를 찾고, 각 단어가 몇 번이나 등장하였는지 조사하기

  - 문장을 공백문자(띄어쓰기, 탭, 엔터 등)를 기준으로 하는 단어로 단순 분리

  - 공백과 공백 사이의 모든 문자는 하나의 단어임

  ex) 예시문장: Big-data is big, MapReduce IS for big-data!

  예시문장으로부터 추출한 단어: "Big-data", "is", "big,", "MapReduce", "IS", "for", "big-data!"

  -> "Big-data"와 "big-data!", "is"와 "IS"는 서로 다른 단어로 취급

  ## 제출

  1. 본 과제를 수행한 방법에 대한 간략한 보고서

  2. 가장 많이 등장한 1000개의 단어를 빈도순으로 정렬하여 저장한 파일

  ex)

  The   123456

  of    31234

  this  21123