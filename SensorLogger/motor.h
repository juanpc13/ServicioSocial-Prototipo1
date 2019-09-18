void motorLoop() {
  if (millis() - lastMotorTime < activeMotorTime && millis() > activeMotorTime) {
    digitalWrite(motor, HIGH);
  } else {
    digitalWrite(motor, LOW);
  }
}
