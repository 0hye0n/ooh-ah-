import cv2

count = 0
cap = cv2.VideoCapture("./test.mp4")

#동영상 읽이 못할 경우 1초 마다 반복하며 계속 못받을시 Wait for the heather 출력
while not cap.isOpened():
    cap = cv2.VideoCapture("./test.mp4")
    cv2.waitKey(1000)
    print("Wait for the header")

face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

#캡처한 영상의 속성을리턴
#CV_CAP_PROP_POS_FRAMES -> 0-based index of the frame to be decoded/captured next
#다음에 디코드/캡쳐되는 프레임의 0베이스 인덱스
pos_frame = cap.get(cv2.CAP_PROP_POS_FRAMES)

while True:
    #decode frame을 읽어옴 frame이 없을 경우 false를 리턴
    flag, frame = cap.read()

    #frame이 있을 경우
    if flag:
        # The frame is ready and already captured
        #cv2.imshow('video', frame)

        # 몇번째 캡쳐인지 읽어옴
        pos_frame = cap.get(cv2.CAP_PROP_POS_FRAMES)
        count += 1
        print(str(pos_frame)+" frames")
        frame = cv2.resize(frame, dsize=(400, 400), fx=1, fy=1, interpolation=cv2.INTER_LINEAR)

        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        faces = face_cascade.detectMultiScale(gray, 2, 5)
        flag = False
        for (x, y, w, h) in faces:
            flag = True
            cv2.rectangle(frame, (x, y), (x+w, y+h), (255, 0, 0), 2)

        #cv2.imshow('frame', frame)
        if flag:
            cv2.imwrite("C:\\Users\\bueno\\Desktop\\frameOpenCV\\frame%d.jpg" % count, frame)



    else:
        # The next frame is not ready, so we try to read it again
        cap.set(cv2.CAP_PROP_POS_FRAMES, pos_frame-1)
        print("frame is not ready")
        # It is better to wait for a while for the next frame to be ready
        cv2.waitKey(1000)

    if cv2.waitKey(10) == 27:
        break

    #전체 프레임수랑 현재 캡쳐하는 프레임수가 같을 경우 끝냄

    if cap.get(cv2.CAP_PROP_POS_FRAMES) == cap.get(cv2.CAP_PROP_FRAME_COUNT):
        # If the number of captured frames is equal to the total number of frames,
        # we stop
        break

cap.release()
cv2.destroyAllWindows()