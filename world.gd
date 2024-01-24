extends Node2D

@onready var bullet_container = $BulletContainer

@onready var player = $Player
# Called when the node enters the scene tree for the first time.
func _ready():
	player.bullet_shot.connect(_on_player_bullet_shot)


func _on_player_bullet_shot(bullet_scene, location, direction):
	var bullet = bullet_scene.instantiate()
	bullet.global_position = location
	bullet.direction = direction
	bullet_container.add_child(bullet)
