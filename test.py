import cv2

class camera:
    def __init__(self, cam_id = 1, width = 640, height = 480):
        self.width = 640
        self.cam_id = cam_id
        self.width = width
        self.height = height
    def get_img(self):
        IpLastSegment = "15"
        cam = self.cam_id
        udpstrPrevData = "udpsrc port=9201"
        udpPORT = [9201,9202,9203,9204,9205]
        udpstrBehindData = " ! application/x-rtp,media=video,encoding-name=H264 ! rtph264depay ! h264parse ! avdec_h264 ! decodebin ! videoconvert ! appsink"
        udpSendIntegratedPipe_0 = udpstrPrevData + udpstrBehindData
        print(udpSendIntegratedPipe_0)

        self.cap = cv2.VideoCapture(udpSendIntegratedPipe_0, cv2.CAP_GSTREAMER)

    def demo(self):
        self.get_img()    
        while(True):
            self.ret, self.frame = self.cap.read()
            if not self.ret:
                print("Failed to receive frame")
                return
            self.frame = cv2.resize(self.frame, (self.width, self.height))
            if self.cam_id == 1:
                self.frame = cv2.flip(self.frame, -1)
            if self.frame is not None:
                cv2.imshow("video0", self.frame)
            if cv2.waitKey(2) & 0xFF == ord('q'):
                break
        self.cap.release()
        cv2.destroyAllWindows()

if __name__=="__main__":
    print(cv2.getBuildInformation())
    c = camera()
    c.demo()