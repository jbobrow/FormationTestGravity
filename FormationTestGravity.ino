/*
   Top and Bottom formation test
*/

enum Forms {        // represent the following with simple graphics
  SINGLE,           // BLUE
  SINGLE_CENTER,    // BLUE + CYAN
  DOUBLE,           // RED
  DOUBLE_SPLIT,     // RED + MAGENTA
  TRIPLE,           // GREEN
  NUM_FORMS
};



void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  bool top[3];
  bool bottom[3];

  FOREACH_FACE(f) {
    if (f < 3) {
      top[f] = !isValueReceivedOnFaceExpired(f);
    }
    else {
      bottom[f - 3] = !isValueReceivedOnFaceExpired(f);
    }
  }

  // display values
  // top

  switch (getFormFromArray(top)) {
    case SINGLE:
      setColorOnFace(BLUE, 0);
      setColorOnFace(BLUE, 1);
      setColorOnFace(BLUE, 2);
      break;
    case SINGLE_CENTER:
      setColorOnFace(BLUE, 0);
      setColorOnFace(CYAN, 1);
      setColorOnFace(BLUE, 2);
      break;
    case DOUBLE:
      setColorOnFace(RED, 0);
      setColorOnFace(RED, 1);
      setColorOnFace(RED, 2);
      break;
    case DOUBLE_SPLIT:
      setColorOnFace(RED, 0);
      setColorOnFace(MAGENTA, 1);
      setColorOnFace(RED, 2);
      break;
    case TRIPLE:
      setColorOnFace(GREEN, 0);
      setColorOnFace(GREEN, 1);
      setColorOnFace(GREEN, 2);
      break;
    case NUM_FORMS:
      setColorOnFace(ORANGE, 0);
      setColorOnFace(ORANGE, 1);
      setColorOnFace(ORANGE, 2);
      break;
  }
  // bottom
  switch (getFormFromArray(bottom)) {
    case SINGLE:
      setColorOnFace(BLUE, 3);
      setColorOnFace(BLUE, 4);
      setColorOnFace(BLUE, 5);
      break;
    case SINGLE_CENTER:
      setColorOnFace(BLUE, 3);
      setColorOnFace(CYAN, 4);
      setColorOnFace(BLUE, 5);
      break;
    case DOUBLE:
      setColorOnFace(RED, 3);
      setColorOnFace(RED, 4);
      setColorOnFace(RED, 5);
      break;
    case DOUBLE_SPLIT:
      setColorOnFace(RED, 3);
      setColorOnFace(MAGENTA, 4);
      setColorOnFace(RED, 5);
      break;
    case TRIPLE:
      setColorOnFace(GREEN, 3);
      setColorOnFace(GREEN, 4);
      setColorOnFace(GREEN, 5);
      break;
    case NUM_FORMS:
      setColorOnFace(ORANGE, 3);
      setColorOnFace(ORANGE, 4);
      setColorOnFace(ORANGE, 5);
      break;

  }

}

byte getFormFromArray(bool neighbors[3]) {
  byte count = 0;
  bool centerOccupied = false;
  for (byte i = 0; i < 3; i++) {
    if (neighbors[i]) {
      count++;
      if (i == 1) {
        centerOccupied = true;
      }
    }
  }

  if (count == 1) {
    if (centerOccupied) {
      return SINGLE_CENTER;
    }
    else {
      return SINGLE;
    }
  }
  else if (count == 2) {
    if (centerOccupied) {
      return DOUBLE;
    }
    else {
      return DOUBLE_SPLIT;
    }
  }
  else if (count == 3) {
    return TRIPLE;
  }

  return NUM_FORMS;
}
