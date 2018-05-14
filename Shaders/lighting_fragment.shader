#version 330 core

struct Material {
	sampler2D diffuse1;
	sampler2D diffuse2;
	sampler2D diffuse3;
	sampler2D specular1;
	sampler2D specular2;
	sampler2D specular3;

	float shininess;
};

struct Light {
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

out vec4 color;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main() {
	// Ambient
	vec3 ambient = light.ambient * vec3(texture(material.diffuse1, TexCoords));

	// Diffuse 
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(light.position - FragPos);
	float diff = max(dot(norm, lightDir), 0.0f);
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse1, TexCoords));

	// Specular
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);
	vec3 specular = light.specular * spec * vec3(texture(material.specular1, TexCoords));

	color = vec4(ambient + diffuse + specular, 1.0f);
}