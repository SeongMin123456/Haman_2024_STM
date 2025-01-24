void step_Wave(int step)
{
   switch(step)
   {
   case 0:
      HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, 1);
      HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, 0);
      HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin, 0);
      HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin, 0);
      break;
   case 1:
      HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, 0);
      HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, 1);
      HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin, 0);
      HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin, 0);
      break;
   case 2:
      HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, 0);
      HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, 0);
      HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin, 1);
      HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin, 0);
      break;
   case 3:
      HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, 0);
      HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, 0);
      HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin, 0);
      HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin, 1);
      break;

   }
}
void step_Full(int step)
{
   switch(step)
   {
   case 0:
      HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, 1);
      HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, 1);
      HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin, 0);
      HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin, 0);
      break;
   case 1:
      HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, 0);
      HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, 1);
      HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin, 1);
      HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin, 0);
      break;
   case 2:
      HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, 0);
      HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, 0);
      HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin, 1);
      HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin, 1);
      break;
   case 3:
      HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, 1);
      HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, 0);
      HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin, 0);
      HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin, 1);
      break;

   }
}
void step_Half(int step)
{
   switch(step)
   {
   case 0:
      HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, 1);
      HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, 0);
      HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin, 0);
      HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin, 0);
      break;
   case 1:
      HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, 1);
      HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, 1);
      HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin, 0);
      HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin, 0);
      break;
   case 2:
      HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, 0);
      HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, 1);
      HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin, 0);
      HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin, 0);
      break;
   case 3:
      HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, 0);
      HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, 1);
      HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin, 1);
      HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin, 0);
      break;
   case 4:
      HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, 0);
      HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, 0);
      HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin, 1);
      HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin, 0);
      break;
   case 5:
      HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, 0);
      HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, 0);
      HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin, 1);
      HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin, 1);
      break;
   case 6:
      HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, 0);
      HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, 0);
      HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin, 0);
      HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin, 1);
      break;
   case 7:
      HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, 1);
      HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, 0);
      HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin, 0);
      HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin, 1);
      break;

   }
}