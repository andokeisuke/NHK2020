; Auto-generated. Do not edit!


(cl:in-package custom_msg-msg)


;//! \htmlinclude temp_odom.msg.html

(cl:defclass <temp_odom> (roslisp-msg-protocol:ros-message)
  ((position
    :reader position
    :initarg :position
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (velocity
    :reader velocity
    :initarg :velocity
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3)))
)

(cl:defclass temp_odom (<temp_odom>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <temp_odom>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'temp_odom)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name custom_msg-msg:<temp_odom> is deprecated: use custom_msg-msg:temp_odom instead.")))

(cl:ensure-generic-function 'position-val :lambda-list '(m))
(cl:defmethod position-val ((m <temp_odom>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:position-val is deprecated.  Use custom_msg-msg:position instead.")
  (position m))

(cl:ensure-generic-function 'velocity-val :lambda-list '(m))
(cl:defmethod velocity-val ((m <temp_odom>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:velocity-val is deprecated.  Use custom_msg-msg:velocity instead.")
  (velocity m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <temp_odom>) ostream)
  "Serializes a message object of type '<temp_odom>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'position) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'velocity) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <temp_odom>) istream)
  "Deserializes a message object of type '<temp_odom>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'position) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'velocity) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<temp_odom>)))
  "Returns string type for a message object of type '<temp_odom>"
  "custom_msg/temp_odom")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'temp_odom)))
  "Returns string type for a message object of type 'temp_odom"
  "custom_msg/temp_odom")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<temp_odom>)))
  "Returns md5sum for a message object of type '<temp_odom>"
  "589dbd8c358d253de2ab5441acd36a2b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'temp_odom)))
  "Returns md5sum for a message object of type 'temp_odom"
  "589dbd8c358d253de2ab5441acd36a2b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<temp_odom>)))
  "Returns full string definition for message of type '<temp_odom>"
  (cl:format cl:nil "geometry_msgs/Vector3 position~%geometry_msgs/Vector3 velocity~%~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'temp_odom)))
  "Returns full string definition for message of type 'temp_odom"
  (cl:format cl:nil "geometry_msgs/Vector3 position~%geometry_msgs/Vector3 velocity~%~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <temp_odom>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'position))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'velocity))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <temp_odom>))
  "Converts a ROS message object to a list"
  (cl:list 'temp_odom
    (cl:cons ':position (position msg))
    (cl:cons ':velocity (velocity msg))
))
