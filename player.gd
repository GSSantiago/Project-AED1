extends CharacterBody2D

signal bullet_shot(bullet_scene, location)

@onready var marker = $Marker2D

@export var SPEED : int = 70
@export var lastDir: String = "right"

var bullet_scene = preload("res://Bullet.tscn")

func _process(delta):
	if Input.is_action_just_pressed("shoot"):
		shoot()
	pass


func animateIdle():
	$AnimatedSprite2D.flip_h = false
	if(lastDir == "left"):
		$AnimatedSprite2D.play("Idle_Horizontal")
		$AnimatedSprite2D.flip_h = true
	elif(lastDir == "right"):
		$AnimatedSprite2D.play("Idle_Horizontal")
	elif(lastDir == "up"):
		$AnimatedSprite2D.pause()
	elif(lastDir == "down"):
		$AnimatedSprite2D.pause()
		
		
func _physics_process(delta):
	
	var dirHorizontal = Input.get_axis("left", "right")
	var dirVertical = Input.get_axis("up", "down")
	
	if dirHorizontal:
		$AnimatedSprite2D.flip_h = false
		velocity.x = dirHorizontal * SPEED
		if dirHorizontal == 1:
			marker.position.x = 15
			$AnimatedSprite2D.play("Right")
			lastDir = "right";
		elif dirHorizontal == -1:
				marker.position.x = -12
				$AnimatedSprite2D.play("Left")	
				lastDir = "left";
	else:	
		velocity.x = 0
		if not dirVertical:
			animateIdle()
		
	if(dirVertical):
		#$AnimatedSprite2D.flip_h = false
		velocity.y = dirVertical * SPEED
		if dirVertical == 1:
			marker.position.y = 4
			marker.position.x = 10
			$AnimatedSprite2D.play("Down")
			lastDir = "down";
			
		elif dirVertical == -1:
				marker.position.y = -7.5
				marker.position.x = -2.5
				$AnimatedSprite2D.play("Up")	
				lastDir = "up";
				
	else:
		velocity.y = 0	
		if not dirHorizontal:
			animateIdle()
	
	
	move_and_slide()

func shoot():
	bullet_shot.emit(bullet_scene, marker.global_position, lastDir)
	
	
