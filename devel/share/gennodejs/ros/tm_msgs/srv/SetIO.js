// Auto-generated. Do not edit!

// (in-package tm_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class SetIORequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.fun = null;
      this.ch = null;
      this.value = null;
    }
    else {
      if (initObj.hasOwnProperty('fun')) {
        this.fun = initObj.fun
      }
      else {
        this.fun = 0;
      }
      if (initObj.hasOwnProperty('ch')) {
        this.ch = initObj.ch
      }
      else {
        this.ch = 0;
      }
      if (initObj.hasOwnProperty('value')) {
        this.value = initObj.value
      }
      else {
        this.value = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SetIORequest
    // Serialize message field [fun]
    bufferOffset = _serializer.int8(obj.fun, buffer, bufferOffset);
    // Serialize message field [ch]
    bufferOffset = _serializer.int8(obj.ch, buffer, bufferOffset);
    // Serialize message field [value]
    bufferOffset = _serializer.float32(obj.value, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SetIORequest
    let len;
    let data = new SetIORequest(null);
    // Deserialize message field [fun]
    data.fun = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [ch]
    data.ch = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [value]
    data.value = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 6;
  }

  static datatype() {
    // Returns string type for a service object
    return 'tm_msgs/SetIORequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2ba9b06479f48a80313812c352c3f674';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int8 FUN_SET_MB_DIGITAL_OUT = 1
    int8 FUN_SET_MB_ANALOG_OUT = 2
    int8 FUN_SET_EE_DIGITAL_OUT = 3
    int8 FUN_SET_EE_ANALOG_OUT = 4
    int8 fun
    int8 ch
    float32 value
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SetIORequest(null);
    if (msg.fun !== undefined) {
      resolved.fun = msg.fun;
    }
    else {
      resolved.fun = 0
    }

    if (msg.ch !== undefined) {
      resolved.ch = msg.ch;
    }
    else {
      resolved.ch = 0
    }

    if (msg.value !== undefined) {
      resolved.value = msg.value;
    }
    else {
      resolved.value = 0.0
    }

    return resolved;
    }
};

// Constants for message
SetIORequest.Constants = {
  FUN_SET_MB_DIGITAL_OUT: 1,
  FUN_SET_MB_ANALOG_OUT: 2,
  FUN_SET_EE_DIGITAL_OUT: 3,
  FUN_SET_EE_ANALOG_OUT: 4,
}

class SetIOResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.success = null;
    }
    else {
      if (initObj.hasOwnProperty('success')) {
        this.success = initObj.success
      }
      else {
        this.success = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SetIOResponse
    // Serialize message field [success]
    bufferOffset = _serializer.bool(obj.success, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SetIOResponse
    let len;
    let data = new SetIOResponse(null);
    // Deserialize message field [success]
    data.success = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'tm_msgs/SetIOResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '358e233cde0c8a8bcfea4ce193f8fc15';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool success
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SetIOResponse(null);
    if (msg.success !== undefined) {
      resolved.success = msg.success;
    }
    else {
      resolved.success = false
    }

    return resolved;
    }
};

module.exports = {
  Request: SetIORequest,
  Response: SetIOResponse,
  md5sum() { return 'dd90dc6f465eb8532180f93ce5e1fa2e'; },
  datatype() { return 'tm_msgs/SetIO'; }
};
