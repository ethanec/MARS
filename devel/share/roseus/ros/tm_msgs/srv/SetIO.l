;; Auto-generated. Do not edit!


(when (boundp 'tm_msgs::SetIO)
  (if (not (find-package "TM_MSGS"))
    (make-package "TM_MSGS"))
  (shadow 'SetIO (find-package "TM_MSGS")))
(unless (find-package "TM_MSGS::SETIO")
  (make-package "TM_MSGS::SETIO"))
(unless (find-package "TM_MSGS::SETIOREQUEST")
  (make-package "TM_MSGS::SETIOREQUEST"))
(unless (find-package "TM_MSGS::SETIORESPONSE")
  (make-package "TM_MSGS::SETIORESPONSE"))

(in-package "ROS")





(intern "*FUN_SET_MB_DIGITAL_OUT*" (find-package "TM_MSGS::SETIOREQUEST"))
(shadow '*FUN_SET_MB_DIGITAL_OUT* (find-package "TM_MSGS::SETIOREQUEST"))
(defconstant tm_msgs::SetIORequest::*FUN_SET_MB_DIGITAL_OUT* 1)
(intern "*FUN_SET_MB_ANALOG_OUT*" (find-package "TM_MSGS::SETIOREQUEST"))
(shadow '*FUN_SET_MB_ANALOG_OUT* (find-package "TM_MSGS::SETIOREQUEST"))
(defconstant tm_msgs::SetIORequest::*FUN_SET_MB_ANALOG_OUT* 2)
(intern "*FUN_SET_EE_DIGITAL_OUT*" (find-package "TM_MSGS::SETIOREQUEST"))
(shadow '*FUN_SET_EE_DIGITAL_OUT* (find-package "TM_MSGS::SETIOREQUEST"))
(defconstant tm_msgs::SetIORequest::*FUN_SET_EE_DIGITAL_OUT* 3)
(intern "*FUN_SET_EE_ANALOG_OUT*" (find-package "TM_MSGS::SETIOREQUEST"))
(shadow '*FUN_SET_EE_ANALOG_OUT* (find-package "TM_MSGS::SETIOREQUEST"))
(defconstant tm_msgs::SetIORequest::*FUN_SET_EE_ANALOG_OUT* 4)
(defclass tm_msgs::SetIORequest
  :super ros::object
  :slots (_fun _ch _value ))

(defmethod tm_msgs::SetIORequest
  (:init
   (&key
    ((:fun __fun) 0)
    ((:ch __ch) 0)
    ((:value __value) 0.0)
    )
   (send-super :init)
   (setq _fun (round __fun))
   (setq _ch (round __ch))
   (setq _value (float __value))
   self)
  (:fun
   (&optional __fun)
   (if __fun (setq _fun __fun)) _fun)
  (:ch
   (&optional __ch)
   (if __ch (setq _ch __ch)) _ch)
  (:value
   (&optional __value)
   (if __value (setq _value __value)) _value)
  (:serialization-length
   ()
   (+
    ;; int8 _fun
    1
    ;; int8 _ch
    1
    ;; float32 _value
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int8 _fun
       (write-byte _fun s)
     ;; int8 _ch
       (write-byte _ch s)
     ;; float32 _value
       (sys::poke _value (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int8 _fun
     (setq _fun (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _fun 127) (setq _fun (- _fun 256)))
   ;; int8 _ch
     (setq _ch (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _ch 127) (setq _ch (- _ch 256)))
   ;; float32 _value
     (setq _value (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(defclass tm_msgs::SetIOResponse
  :super ros::object
  :slots (_success ))

(defmethod tm_msgs::SetIOResponse
  (:init
   (&key
    ((:success __success) nil)
    )
   (send-super :init)
   (setq _success __success)
   self)
  (:success
   (&optional __success)
   (if __success (setq _success __success)) _success)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass tm_msgs::SetIO
  :super ros::object
  :slots ())

(setf (get tm_msgs::SetIO :md5sum-) "dd90dc6f465eb8532180f93ce5e1fa2e")
(setf (get tm_msgs::SetIO :datatype-) "tm_msgs/SetIO")
(setf (get tm_msgs::SetIO :request) tm_msgs::SetIORequest)
(setf (get tm_msgs::SetIO :response) tm_msgs::SetIOResponse)

(defmethod tm_msgs::SetIORequest
  (:response () (instance tm_msgs::SetIOResponse :init)))

(setf (get tm_msgs::SetIORequest :md5sum-) "dd90dc6f465eb8532180f93ce5e1fa2e")
(setf (get tm_msgs::SetIORequest :datatype-) "tm_msgs/SetIORequest")
(setf (get tm_msgs::SetIORequest :definition-)
      "int8 FUN_SET_MB_DIGITAL_OUT = 1
int8 FUN_SET_MB_ANALOG_OUT = 2
int8 FUN_SET_EE_DIGITAL_OUT = 3
int8 FUN_SET_EE_ANALOG_OUT = 4
int8 fun
int8 ch
float32 value
---
bool success

")

(setf (get tm_msgs::SetIOResponse :md5sum-) "dd90dc6f465eb8532180f93ce5e1fa2e")
(setf (get tm_msgs::SetIOResponse :datatype-) "tm_msgs/SetIOResponse")
(setf (get tm_msgs::SetIOResponse :definition-)
      "int8 FUN_SET_MB_DIGITAL_OUT = 1
int8 FUN_SET_MB_ANALOG_OUT = 2
int8 FUN_SET_EE_DIGITAL_OUT = 3
int8 FUN_SET_EE_ANALOG_OUT = 4
int8 fun
int8 ch
float32 value
---
bool success

")



(provide :tm_msgs/SetIO "dd90dc6f465eb8532180f93ce5e1fa2e")


