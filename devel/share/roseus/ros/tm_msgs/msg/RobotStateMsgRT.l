;; Auto-generated. Do not edit!


(when (boundp 'tm_msgs::RobotStateMsgRT)
  (if (not (find-package "TM_MSGS"))
    (make-package "TM_MSGS"))
  (shadow 'RobotStateMsgRT (find-package "TM_MSGS")))
(unless (find-package "TM_MSGS::ROBOTSTATEMSGRT")
  (make-package "TM_MSGS::ROBOTSTATEMSGRT"))

(in-package "ROS")
;;//! \htmlinclude RobotStateMsgRT.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass tm_msgs::RobotStateMsgRT
  :super ros::object
  :slots (_header _time _controller_time _q_command _qd_command _qt_command _q_actual _qd_actual _qt_actual _tool0_pos_command _tool0_pos_actual _tool_pos_command _tool_pos_actual _tcp_speed _tcp_force _kine_config _common_speed_ratio _robot_mode _safety_mode _teach_mode _control_mode _error_code_0 _error_code_1 ))

(defmethod tm_msgs::RobotStateMsgRT
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:time __time) 0.0)
    ((:controller_time __controller_time) 0.0)
    ((:q_command __q_command) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:qd_command __qd_command) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:qt_command __qt_command) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:q_actual __q_actual) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:qd_actual __qd_actual) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:qt_actual __qt_actual) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:tool0_pos_command __tool0_pos_command) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:tool0_pos_actual __tool0_pos_actual) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:tool_pos_command __tool_pos_command) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:tool_pos_actual __tool_pos_actual) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:tcp_speed __tcp_speed) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:tcp_force __tcp_force) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:kine_config __kine_config) (make-array 0 :initial-element 0 :element-type :integer))
    ((:common_speed_ratio __common_speed_ratio) 0.0)
    ((:robot_mode __robot_mode) 0)
    ((:safety_mode __safety_mode) 0)
    ((:teach_mode __teach_mode) 0)
    ((:control_mode __control_mode) 0)
    ((:error_code_0 __error_code_0) 0)
    ((:error_code_1 __error_code_1) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _time (float __time))
   (setq _controller_time (float __controller_time))
   (setq _q_command __q_command)
   (setq _qd_command __qd_command)
   (setq _qt_command __qt_command)
   (setq _q_actual __q_actual)
   (setq _qd_actual __qd_actual)
   (setq _qt_actual __qt_actual)
   (setq _tool0_pos_command __tool0_pos_command)
   (setq _tool0_pos_actual __tool0_pos_actual)
   (setq _tool_pos_command __tool_pos_command)
   (setq _tool_pos_actual __tool_pos_actual)
   (setq _tcp_speed __tcp_speed)
   (setq _tcp_force __tcp_force)
   (setq _kine_config __kine_config)
   (setq _common_speed_ratio (float __common_speed_ratio))
   (setq _robot_mode (round __robot_mode))
   (setq _safety_mode (round __safety_mode))
   (setq _teach_mode (round __teach_mode))
   (setq _control_mode (round __control_mode))
   (setq _error_code_0 (round __error_code_0))
   (setq _error_code_1 (round __error_code_1))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:time
   (&optional __time)
   (if __time (setq _time __time)) _time)
  (:controller_time
   (&optional __controller_time)
   (if __controller_time (setq _controller_time __controller_time)) _controller_time)
  (:q_command
   (&optional __q_command)
   (if __q_command (setq _q_command __q_command)) _q_command)
  (:qd_command
   (&optional __qd_command)
   (if __qd_command (setq _qd_command __qd_command)) _qd_command)
  (:qt_command
   (&optional __qt_command)
   (if __qt_command (setq _qt_command __qt_command)) _qt_command)
  (:q_actual
   (&optional __q_actual)
   (if __q_actual (setq _q_actual __q_actual)) _q_actual)
  (:qd_actual
   (&optional __qd_actual)
   (if __qd_actual (setq _qd_actual __qd_actual)) _qd_actual)
  (:qt_actual
   (&optional __qt_actual)
   (if __qt_actual (setq _qt_actual __qt_actual)) _qt_actual)
  (:tool0_pos_command
   (&optional __tool0_pos_command)
   (if __tool0_pos_command (setq _tool0_pos_command __tool0_pos_command)) _tool0_pos_command)
  (:tool0_pos_actual
   (&optional __tool0_pos_actual)
   (if __tool0_pos_actual (setq _tool0_pos_actual __tool0_pos_actual)) _tool0_pos_actual)
  (:tool_pos_command
   (&optional __tool_pos_command)
   (if __tool_pos_command (setq _tool_pos_command __tool_pos_command)) _tool_pos_command)
  (:tool_pos_actual
   (&optional __tool_pos_actual)
   (if __tool_pos_actual (setq _tool_pos_actual __tool_pos_actual)) _tool_pos_actual)
  (:tcp_speed
   (&optional __tcp_speed)
   (if __tcp_speed (setq _tcp_speed __tcp_speed)) _tcp_speed)
  (:tcp_force
   (&optional __tcp_force)
   (if __tcp_force (setq _tcp_force __tcp_force)) _tcp_force)
  (:kine_config
   (&optional __kine_config)
   (if __kine_config (setq _kine_config __kine_config)) _kine_config)
  (:common_speed_ratio
   (&optional __common_speed_ratio)
   (if __common_speed_ratio (setq _common_speed_ratio __common_speed_ratio)) _common_speed_ratio)
  (:robot_mode
   (&optional __robot_mode)
   (if __robot_mode (setq _robot_mode __robot_mode)) _robot_mode)
  (:safety_mode
   (&optional __safety_mode)
   (if __safety_mode (setq _safety_mode __safety_mode)) _safety_mode)
  (:teach_mode
   (&optional __teach_mode)
   (if __teach_mode (setq _teach_mode __teach_mode)) _teach_mode)
  (:control_mode
   (&optional __control_mode)
   (if __control_mode (setq _control_mode __control_mode)) _control_mode)
  (:error_code_0
   (&optional __error_code_0)
   (if __error_code_0 (setq _error_code_0 __error_code_0)) _error_code_0)
  (:error_code_1
   (&optional __error_code_1)
   (if __error_code_1 (setq _error_code_1 __error_code_1)) _error_code_1)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float64 _time
    8
    ;; float64 _controller_time
    8
    ;; float64[] _q_command
    (* 8    (length _q_command)) 4
    ;; float64[] _qd_command
    (* 8    (length _qd_command)) 4
    ;; float64[] _qt_command
    (* 8    (length _qt_command)) 4
    ;; float64[] _q_actual
    (* 8    (length _q_actual)) 4
    ;; float64[] _qd_actual
    (* 8    (length _qd_actual)) 4
    ;; float64[] _qt_actual
    (* 8    (length _qt_actual)) 4
    ;; float64[] _tool0_pos_command
    (* 8    (length _tool0_pos_command)) 4
    ;; float64[] _tool0_pos_actual
    (* 8    (length _tool0_pos_actual)) 4
    ;; float64[] _tool_pos_command
    (* 8    (length _tool_pos_command)) 4
    ;; float64[] _tool_pos_actual
    (* 8    (length _tool_pos_actual)) 4
    ;; float64[] _tcp_speed
    (* 8    (length _tcp_speed)) 4
    ;; float64[] _tcp_force
    (* 8    (length _tcp_force)) 4
    ;; int32[] _kine_config
    (* 4    (length _kine_config)) 4
    ;; float64 _common_speed_ratio
    8
    ;; int32 _robot_mode
    4
    ;; int32 _safety_mode
    4
    ;; int32 _teach_mode
    4
    ;; int32 _control_mode
    4
    ;; int32 _error_code_0
    4
    ;; int32 _error_code_1
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float64 _time
       (sys::poke _time (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _controller_time
       (sys::poke _controller_time (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64[] _q_command
     (write-long (length _q_command) s)
     (dotimes (i (length _q_command))
       (sys::poke (elt _q_command i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _qd_command
     (write-long (length _qd_command) s)
     (dotimes (i (length _qd_command))
       (sys::poke (elt _qd_command i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _qt_command
     (write-long (length _qt_command) s)
     (dotimes (i (length _qt_command))
       (sys::poke (elt _qt_command i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _q_actual
     (write-long (length _q_actual) s)
     (dotimes (i (length _q_actual))
       (sys::poke (elt _q_actual i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _qd_actual
     (write-long (length _qd_actual) s)
     (dotimes (i (length _qd_actual))
       (sys::poke (elt _qd_actual i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _qt_actual
     (write-long (length _qt_actual) s)
     (dotimes (i (length _qt_actual))
       (sys::poke (elt _qt_actual i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _tool0_pos_command
     (write-long (length _tool0_pos_command) s)
     (dotimes (i (length _tool0_pos_command))
       (sys::poke (elt _tool0_pos_command i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _tool0_pos_actual
     (write-long (length _tool0_pos_actual) s)
     (dotimes (i (length _tool0_pos_actual))
       (sys::poke (elt _tool0_pos_actual i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _tool_pos_command
     (write-long (length _tool_pos_command) s)
     (dotimes (i (length _tool_pos_command))
       (sys::poke (elt _tool_pos_command i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _tool_pos_actual
     (write-long (length _tool_pos_actual) s)
     (dotimes (i (length _tool_pos_actual))
       (sys::poke (elt _tool_pos_actual i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _tcp_speed
     (write-long (length _tcp_speed) s)
     (dotimes (i (length _tcp_speed))
       (sys::poke (elt _tcp_speed i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _tcp_force
     (write-long (length _tcp_force) s)
     (dotimes (i (length _tcp_force))
       (sys::poke (elt _tcp_force i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; int32[] _kine_config
     (write-long (length _kine_config) s)
     (dotimes (i (length _kine_config))
       (write-long (elt _kine_config i) s)
       )
     ;; float64 _common_speed_ratio
       (sys::poke _common_speed_ratio (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int32 _robot_mode
       (write-long _robot_mode s)
     ;; int32 _safety_mode
       (write-long _safety_mode s)
     ;; int32 _teach_mode
       (write-long _teach_mode s)
     ;; int32 _control_mode
       (write-long _control_mode s)
     ;; int32 _error_code_0
       (write-long _error_code_0 s)
     ;; int32 _error_code_1
       (write-long _error_code_1 s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float64 _time
     (setq _time (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _controller_time
     (setq _controller_time (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64[] _q_command
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _q_command (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _q_command i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _qd_command
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _qd_command (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _qd_command i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _qt_command
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _qt_command (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _qt_command i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _q_actual
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _q_actual (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _q_actual i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _qd_actual
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _qd_actual (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _qd_actual i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _qt_actual
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _qt_actual (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _qt_actual i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _tool0_pos_command
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _tool0_pos_command (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _tool0_pos_command i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _tool0_pos_actual
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _tool0_pos_actual (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _tool0_pos_actual i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _tool_pos_command
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _tool_pos_command (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _tool_pos_command i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _tool_pos_actual
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _tool_pos_actual (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _tool_pos_actual i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _tcp_speed
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _tcp_speed (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _tcp_speed i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _tcp_force
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _tcp_force (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _tcp_force i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; int32[] _kine_config
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _kine_config (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _kine_config i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; float64 _common_speed_ratio
     (setq _common_speed_ratio (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int32 _robot_mode
     (setq _robot_mode (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _safety_mode
     (setq _safety_mode (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _teach_mode
     (setq _teach_mode (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _control_mode
     (setq _control_mode (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _error_code_0
     (setq _error_code_0 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _error_code_1
     (setq _error_code_1 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get tm_msgs::RobotStateMsgRT :md5sum-) "b44d2ec991068109b7dfd7a73666f138")
(setf (get tm_msgs::RobotStateMsgRT :datatype-) "tm_msgs/RobotStateMsgRT")
(setf (get tm_msgs::RobotStateMsgRT :definition-)
      "# Data structure for the realtime communications interface
# used by the Techman Robot controller
# 
# This data structure is send at 100 Hz on TCP port 6188

Header header
float64 time
float64 controller_time
float64[] q_command
float64[] qd_command
float64[] qt_command
float64[] q_actual
float64[] qd_actual
float64[] qt_actual
float64[] tool0_pos_command
float64[] tool0_pos_actual
float64[] tool_pos_command
float64[] tool_pos_actual
float64[] tcp_speed
float64[] tcp_force
int32[] kine_config
float64 common_speed_ratio
int32 robot_mode
int32 safety_mode
int32 teach_mode
int32 control_mode
int32 error_code_0
int32 error_code_1

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

")



(provide :tm_msgs/RobotStateMsgRT "b44d2ec991068109b7dfd7a73666f138")


