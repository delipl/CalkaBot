int goBackward(int speed){
	//speed = map(speed, 100, 1000);
	 __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2, speed);
	 __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2, speed);

	 HAL_GPIO_WritePin(Ma1_GPIO_Port, Ma1_Pin, RESET);
	 HAL_GPIO_WritePin(Ma2_GPIO_Port, Ma2_Pin, SET);

	 HAL_GPIO_WritePin(Mb1_GPIO_Port, Mb1_Pin, SET);
	 HAL_GPIO_WritePin(Mb2_GPIO_Port, Mb2_Pin, RESET);
	 return 1;	//accel tutaj bedzie sprawdzany
}

int goForward(int speed){
	//speed = map(speed, 100, 1000);
	 __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2, speed);
	 __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2, speed);

	 HAL_GPIO_WritePin(Ma1_GPIO_Port, Ma1_Pin, SET);
	 HAL_GPIO_WritePin(Ma2_GPIO_Port, Ma2_Pin, RESET);

	 HAL_GPIO_WritePin(Mb1_GPIO_Port, Mb1_Pin, RESET);
	 HAL_GPIO_WritePin(Mb2_GPIO_Port, Mb2_Pin, SET);
	 return 1;
}

int goLeft(int speed){
	//speed = map(speed, 100, 1000);
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2, speed);
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2, speed);

	HAL_GPIO_WritePin(Ma1_GPIO_Port, Ma1_Pin, SET);
	HAL_GPIO_WritePin(Ma2_GPIO_Port, Ma2_Pin, RESET);

	HAL_GPIO_WritePin(Mb1_GPIO_Port, Mb1_Pin, SET);
	HAL_GPIO_WritePin(Mb2_GPIO_Port, Mb2_Pin, RESET);
	return 1;
}

int goRight(int speed){
	//speed = map(speed, 100, 1000);
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2, speed);
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2, speed);

	HAL_GPIO_WritePin(Ma1_GPIO_Port, Ma1_Pin, RESET);
	HAL_GPIO_WritePin(Ma2_GPIO_Port, Ma2_Pin, SET);

	HAL_GPIO_WritePin(Mb1_GPIO_Port, Mb1_Pin, RESET);
	HAL_GPIO_WritePin(Mb2_GPIO_Port, Mb2_Pin, SET);
	return 1;
}

int hardStop(){
	HAL_GPIO_WritePin(Ma1_GPIO_Port, Ma1_Pin, SET);
	HAL_GPIO_WritePin(Ma2_GPIO_Port, Ma2_Pin, SET);

	HAL_GPIO_WritePin(Mb1_GPIO_Port, Mb1_Pin, SET);
	HAL_GPIO_WritePin(Mb2_GPIO_Port, Mb2_Pin, SET);
	return 1;
}

int slowStop(){
	HAL_GPIO_WritePin(Ma1_GPIO_Port, Ma1_Pin, RESET);
	HAL_GPIO_WritePin(Ma2_GPIO_Port, Ma2_Pin, RESET);

	HAL_GPIO_WritePin(Mb1_GPIO_Port, Mb1_Pin, RESET);
	HAL_GPIO_WritePin(Mb2_GPIO_Port, Mb2_Pin, RESET);
	return 1;
}
