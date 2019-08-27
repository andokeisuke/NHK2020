
(cl:in-package :asdf)

(defsystem "custom_msg-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "Nineaxis_sensor" :depends-on ("_package_Nineaxis_sensor"))
    (:file "_package_Nineaxis_sensor" :depends-on ("_package"))
    (:file "RL" :depends-on ("_package_RL"))
    (:file "_package_RL" :depends-on ("_package"))
    (:file "temp_odom" :depends-on ("_package_temp_odom"))
    (:file "_package_temp_odom" :depends-on ("_package"))
    (:file "valve_msg" :depends-on ("_package_valve_msg"))
    (:file "_package_valve_msg" :depends-on ("_package"))
    (:file "wh_msg" :depends-on ("_package_wh_msg"))
    (:file "_package_wh_msg" :depends-on ("_package"))
  ))