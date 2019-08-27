; Auto-generated. Do not edit!


(cl:in-package custom_msg-msg)


;//! \htmlinclude wh_msg.msg.html

(cl:defclass <wh_msg> (roslisp-msg-protocol:ros-message)
  ((st_target_deg
    :reader st_target_deg
    :initarg :st_target_deg
    :type cl:float
    :initform 0.0)
   (st_now_deg
    :reader st_now_deg
    :initarg :st_now_deg
    :type cl:float
    :initform 0.0)
   (wh_target_vel
    :reader wh_target_vel
    :initarg :wh_target_vel
    :type cl:float
    :initform 0.0)
   (wh_now_vel
    :reader wh_now_vel
    :initarg :wh_now_vel
    :type cl:float
    :initform 0.0))
)

(cl:defclass wh_msg (<wh_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <wh_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'wh_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name custom_msg-msg:<wh_msg> is deprecated: use custom_msg-msg:wh_msg instead.")))

(cl:ensure-generic-function 'st_target_deg-val :lambda-list '(m))
(cl:defmethod st_target_deg-val ((m <wh_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:st_target_deg-val is deprecated.  Use custom_msg-msg:st_target_deg instead.")
  (st_target_deg m))

(cl:ensure-generic-function 'st_now_deg-val :lambda-list '(m))
(cl:defmethod st_now_deg-val ((m <wh_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:st_now_deg-val is deprecated.  Use custom_msg-msg:st_now_deg instead.")
  (st_now_deg m))

(cl:ensure-generic-function 'wh_target_vel-val :lambda-list '(m))
(cl:defmethod wh_target_vel-val ((m <wh_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:wh_target_vel-val is deprecated.  Use custom_msg-msg:wh_target_vel instead.")
  (wh_target_vel m))

(cl:ensure-generic-function 'wh_now_vel-val :lambda-list '(m))
(cl:defmethod wh_now_vel-val ((m <wh_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:wh_now_vel-val is deprecated.  Use custom_msg-msg:wh_now_vel instead.")
  (wh_now_vel m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <wh_msg>) ostream)
  "Serializes a message object of type '<wh_msg>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'st_target_deg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'st_now_deg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'wh_target_vel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'wh_now_vel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <wh_msg>) istream)
  "Deserializes a message object of type '<wh_msg>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'st_target_deg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'st_now_deg) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'wh_target_vel) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'wh_now_vel) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<wh_msg>)))
  "Returns string type for a message object of type '<wh_msg>"
  "custom_msg/wh_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'wh_msg)))
  "Returns string type for a message object of type 'wh_msg"
  "custom_msg/wh_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<wh_msg>)))
  "Returns md5sum for a message object of type '<wh_msg>"
  "f89faf035737b3c1eab14ea32778c58c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'wh_msg)))
  "Returns md5sum for a message object of type 'wh_msg"
  "f89faf035737b3c1eab14ea32778c58c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<wh_msg>)))
  "Returns full string definition for message of type '<wh_msg>"
  (cl:format cl:nil "float64 st_target_deg~%float64 st_now_deg~%float64 wh_target_vel~%float64 wh_now_vel~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'wh_msg)))
  "Returns full string definition for message of type 'wh_msg"
  (cl:format cl:nil "float64 st_target_deg~%float64 st_now_deg~%float64 wh_target_vel~%float64 wh_now_vel~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <wh_msg>))
  (cl:+ 0
     8
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <wh_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'wh_msg
    (cl:cons ':st_target_deg (st_target_deg msg))
    (cl:cons ':st_now_deg (st_now_deg msg))
    (cl:cons ':wh_target_vel (wh_target_vel msg))
    (cl:cons ':wh_now_vel (wh_now_vel msg))
))
