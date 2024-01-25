extends Node2D

@onready var bullet_container = $BulletContainer

@onready var player = $Player

@onready var UI = %UI

func _ready():
	player.bullet_shot.connect(_on_player_bullet_shot)


func _on_player_bullet_shot(bullet_scene, location, direction, hexColor):
	var bullet = bullet_scene.instantiate()
	bullet.global_position = location
	bullet.direction = direction
	bullet.hexColor = hexColor
	bullet_container.add_child(bullet)

func update_ui_ammo(value):
	UI.update_ammo_label(value)

func update_ui_color(hexColor):
	UI.update_color_label(hexColor)
