// Auto-generated. Do not edit!

// (in-package joycon.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class pub_val {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.theta = null;
      this.r = null;
    }
    else {
      if (initObj.hasOwnProperty('theta')) {
        this.theta = initObj.theta
      }
      else {
        this.theta = 0;
      }
      if (initObj.hasOwnProperty('r')) {
        this.r = initObj.r
      }
      else {
        this.r = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type pub_val
    // Serialize message field [theta]
    bufferOffset = _serializer.int32(obj.theta, buffer, bufferOffset);
    // Serialize message field [r]
    bufferOffset = _serializer.int32(obj.r, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type pub_val
    let len;
    let data = new pub_val(null);
    // Deserialize message field [theta]
    data.theta = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [r]
    data.r = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'joycon/pub_val';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '58427f44aac94a7705da0eb1e5227372';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 theta
    int32 r
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new pub_val(null);
    if (msg.theta !== undefined) {
      resolved.theta = msg.theta;
    }
    else {
      resolved.theta = 0
    }

    if (msg.r !== undefined) {
      resolved.r = msg.r;
    }
    else {
      resolved.r = 0
    }

    return resolved;
    }
};

module.exports = pub_val;
