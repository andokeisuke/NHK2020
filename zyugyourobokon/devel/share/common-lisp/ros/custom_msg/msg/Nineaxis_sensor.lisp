; Auto-generated. Do not edit!


(cl:in-package custom_msg-msg)


;//! \htmlinclude Nineaxis_sensor.msg.html

(cl:defclass <Nineaxis_sensor> (roslisp-msg-protocol:ros-message)
  ((accl
    :reader accl
    :initarg :accl
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (gyro
    :reader gyro
    :initarg :gyro
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (mag
    :reader mag
    :initarg :mag
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3)))
)

(cl:defclass Nineaxis_sensor (<Nineaxis_sensor>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Nineaxis_sensor>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Nineaxis_sensor)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name custom_msg-msg:<Nineaxis_sensor> is deprecated: use custom_msg-msg:Nineaxis_sensor instead.")))

(cl:ensure-generic-function 'accl-val :lambda-list '(m))
(cl:defmethod accl-val ((m <Nineaxis_sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:accl-val is deprecated.  Use custom_msg-msg:accl instead.")
  (accl m))

(cl:ensure-generic-function 'gyro-val :lambda-list '(m))
(cl:defmethod gyro-val ((m <Nineaxis_sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:gyro-val is deprecated.  Use custom_msg-msg:gyro instead.")
  (gyro m))

(cl:ensure-generic-function 'mag-val :lambda-list '(m))
(cl:defmethod mag-val ((m <Nineaxis_sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:mag-val is deprecated.  Use custom_msg-msg:mag instead.")
  (mag m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Nineaxis_sensor>) ostream)
  "Serializes a message object of type '<Nineaxis_sensor>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'accl) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'gyro) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'mag) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Nineaxis_sensor>) istream)
  "Deserializes a message object of type '<Nineaxis_sensor>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'accl) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'gyro) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'mag) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Nineaxis_sensor>)))
  "Returns string type for a message object of type '<Nineaxis_sensor>"
  "custom_msg/Nineaxis_sensor")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Nineaxis_sensor)))
  "Returns string type for a message object of type 'Nineaxis_sensor"
  "custom_msg/Nineaxis_sensor")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Nineaxis_sensor>)))
  "Returns md5sum for a message object of type '<Nineaxis_sensor>"
  "f88f64117d491e110b918a22793ff2a1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Nineaxis_sensor)))
  "Returns md5sum for a message object of type 'Nineaxis_sensor"
  "f88f64117d491e110b918a22793ff2a1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Nineaxis_sensor>)))
  "Returns full string definition for message of type '<Nineaxis_sensor>"
  (cl:format cl:nil "geometry_msgs/Vector3 accl~%geometry_msgs/Vector3 gyro~%geometry_msgs/Vector3 mag~%~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Nineaxis_sensor)))
  "Returns full string definition for message of type 'Nineaxis_sensor"
  (cl:format cl:nil "geometry_msgs/Vector3 accl~%geometry_msgs/Vector3 gyro~%geometry_msgs/Vector3 mag~%~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Nineaxis_sensor>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'accl))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'gyro))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'mag))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Nineaxis_sensor>))
  "Converts a ROS message object to a list"
  (cl:list 'Nineaxis_sensor
    (cl:cons ':accl (accl msg))
    (cl:cons ':gyro (gyro msg))
    (cl:cons ':mag (mag msg))
))
