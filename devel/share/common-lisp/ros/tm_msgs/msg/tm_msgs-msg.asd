
(cl:in-package :asdf)

(defsystem "tm_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "RobotStateMsgRT" :depends-on ("_package_RobotStateMsgRT"))
    (:file "_package_RobotStateMsgRT" :depends-on ("_package"))
  ))