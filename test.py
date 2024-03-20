import cv2

if __name__=="__main__":
    print(cv2.getBuildInformation())
    c = cv2.VideoCapture(0)
    while c.isOpened():
        ret, frame = c.read()
        if not ret:
            print("Camera unexpectedly closed")
            break
        cv2.imshow("Camera feed", frame)
        if cv2.waitKey(1) == ord("q"):
            break
        
    c.release()
    cv2.destroyAllWindows()