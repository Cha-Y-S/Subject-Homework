# 문장 생성 확률 계산

 1. 음절 bigram 확률을 이용하여 문장 생성 확률을 계산하시오.
  
  - 방법: 음절 bigram 출현빈도 계산 결과로부터 P(j | i) 계산 후에 입력 문장의 출현 확률을 아래 수식으로 계산

    P(s1,s2,s3, ..., sn) = P(s1 | ^) x P(s2 | s1) x P(s3 | s2) x ... x P(sn | sn-1) x P($ | sn)

  - 입력 예제 문장
    1. 예제 1
        - 나는 밥을 좋아했다
        - 나는 법을 좋아했다
        - 너는 밥을 좋아햇다
        - 노는 법을 조아해따
    2. 예제 2
        - 사진을 찍으러 공원에 갔다
        - 사진을 찍으로 공원에 갔다 
 
 2. 예제 문장을 아래 예와 같이 철자/발음 유사 문장으로 다양하게 구성하여 출현확률을 계산하고 출현확률이 높은 순으로 출력하시오.
    1. 예제 1
        - 나는/너는/노는/나눈/내는/누는/누난/난은/넌은/눈은/논은
        - 밥을/법을/바븜/밤을/범을/밥은/법은/밥울/법운/밥운
        - 좋아했다/조하했다/조아햇다/좋아햇따/조아햇따/조하햇다/졸아했다/졸아햇다
    2. 예제 2
        - 사진을/서진을/소진을/사전을/사진울/사딘을
        - 찍으러/찍으로/찍으라/찍우러/짝우러/짝으러
        - 공원에/공원애/공언에/공운에/공뭔에/곰뭔에
        - 갔다/갔따/갓따/갓다/겄다/것따/깄다/샀다/닸다

### <주의사항>
확률값이 0.0 일 때 어떻게 할지의 문제 -- 매우 작은 값으로 setting

원시말뭉치, 음절 bigram 텍스트 파일, 확률계산 결과 파일 등

### <언어>
파이썬 (또는 C/C++)

### <참고>
말뭉치 파일 -- 세종, 한글위키, KCC 말뭉치 중에서 선택

### <프로그램 사용 방법>
1. my-calculate-sentence-percentage.c
   
    컴파일 후 입력파일로 corpus.txt 파일을 넣어줌

    KCC940_Korean_sentences_EUCKR.txt, gtlee.txt는 정상 작동

    확률 계산할 문장을 키보드로부터 입력받아 확률 계산

    키보드 입력을 끝내려면 q 입력

    이후 프로그램 내부에서 문장 생성 후 각 케이스별 가장 높은 확률을 가지는 문장 및 확률 출력 후 프로그램 종료

2. calculate-sentence-percentage.c
    
    wordcount를 이용해 bigram 음절의 확률과 빈도를 계산하는 프로그램

    대용량 말뭉치 파일에 대해 전처리 과정 필요

    ### PreProcessing

      1. get-ngram을 이용해 bigram 추출

          $ > get-ngram.exe -2 < corpus.txt > bigram.txt

      2. split을 이용해 bigram.txt 나눔

          $ > split.exe -4m bigram.txt

      3. wordcount를 이용해 나눠진 데이터(xaa, xab, ~) 병합

          $ > wordcount.exe -i -new -l xaa

          $ > wordcount.exe -i -new -l xab

          $ > wordcount.exe -i -new -l xac

          ...

          (batch 파일을 생성하는 것이 간편)
      
      4. wordcount 후 생성된 out.txt 사용

    $ > calculate-sentence-percentage -freq out.txt

    freq: 최솟값은 2로, 옵션 부여하지 않을 때 default 값 또한 2

    freq보다 높은 빈도를 가지는 bigram 음절만 count 하도록 하는 옵션

    ### Homework 1

    키보드로부터 입력받은 문장에 대해서 문장 생성 확률을 구함

    q를 입력하면 키보드로부터 입력 중지 후 Homework 2로 넘어감

    ### Homework 2

    dic1과 dic2로부터 만들어진 문장에 대해서 문장 생성 확률을 구한 후 각 케이스별로 문장 생성 확률이 높은 순으로 출력함
    