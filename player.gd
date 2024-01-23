extends CharacterBody2D

@export var SPEED : int = 70
@export var lastDir: String = ""


func animateIdle():
	
	if(lastDir == "left"):
		$AnimatedSprite2D.play("Idle_Horizontal")
		$AnimatedSprite2D.flip_h = true
	elif(lastDir == "right"):
		$AnimatedSprite2D.play("Idle_Horizontal")
		$AnimatedSprite2D.flip_h = false
	elif(lastDir == "up"):
		$AnimatedSprite2D.pause()
	elif(lastDir == "down"):
		$AnimatedSprite2D.pause()
		
pass	
		

func _physics_process(delta):
	
	var dirHorizontal = Input.get_axis("left", "right")
	var dirVertical = Input.get_axis("up", "down")
	
	if dirHorizontal:
		$AnimatedSprite2D.flip_h = false
		velocity.x = dirHorizontal * SPEED
		if dirHorizontal == 1:
			$AnimatedSprite2D.play("Right")
			lastDir = "right";
		elif dirHorizontal == -1:
				$AnimatedSprite2D.play("Left")	
				lastDir = "left";
	else:	
		velocity.x = 0
		if not dirVertical:
			animateIdle()
		
	if(dirVertical):
		velocity.y = dirVertical * SPEED
		if dirVertical == 1:
			$AnimatedSprite2D.play("Down")
			lastDir = "down";
			
		elif dirVertical == -1:
				$AnimatedSprite2D.play("Up")	
				lastDir = "up";
				
	else:
		velocity.y = 0	
		if not dirHorizontal:
			animateIdle()
	
	
	move_and_slide()

