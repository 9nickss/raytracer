# Raytracer - C++ Ray Tracing Engine

A sophisticated C++ ray tracing engine that renders 3D scenes with realistic lighting and shadows. The raytracer reads scene descriptions from configuration files and outputs images in PPM format.

## Features

### Primitives
- **Spheres** - Perfect sphere rendering with smooth shading
- **Planes** - Infinite plane primitives
- **Cylinders** - Infinite cylindrical surfaces
- **Cones** - Infinite conical surfaces
- **Limited Cylinders** - Finite cylinders with capped ends
- **Limited Cones** - Finite cones with capped bases

### Lighting System
- **Ambient Lighting** - Global illumination for base scene brightness
- **Directional Lights** - Parallel light sources (sun-like)
- **Point Lights** ⭐ - Omnidirectional light sources from specific positions
- **Colored Lights** ⭐ - RGB color-aware light sources for realistic color mixing

### Transformations & Geometry ⭐
- **Rotation** - Full 3D rotation around arbitrary axes
- **Scale** - Non-uniform scaling of primitives
- **Shear** - Geometric shearing transformations
- **Camera Control** - Flexible camera positioning and orientation

### Rendering
- **Ray-Primitive Intersection** - Accurate geometric calculations
- **Normal Calculation** - Per-surface normal vectors for correct lighting
- **Color Blending** - Smooth color interpolation based on lighting
- **Recursive Ray Tracing** - Support for complex lighting scenarios

⭐ = Bonus features

## Building

### Prerequisites
- C++17 compatible compiler (clang++ or g++)
- libconfig++ development library

### Compilation
```bash
make
```

The build process will:
1. Compile all source files with C++17 standard
2. Enable optimizations (-O2)
3. Link against libconfig++ for configuration parsing
4. Output the `raytracer` executable

### Cleaning
```bash
make clean      # Remove object files and dependencies
make fclean     # Remove all build artifacts including executable
make re         # Rebuild from scratch
```

## Usage

```bash
./raytracer <config_file.cfg> > <output.ppm>
```

### Basic Example
```bash
./raytracer configs/scene.cfg > output.ppm
```

### Viewing Output
The PPM format can be viewed with standard image viewers:
```bash
# On Linux with GIMP
gimp output.ppm

# On Linux with ImageMagick
display output.ppm

# Convert to PNG
convert output.ppm output.png
```

## Configuration File Format

The raytracer uses libconfig++ format (.cfg files) to define scenes. Here's a complete example:

```config
camera:
{
    position = { x = 0.0; y = 0.0; z = 0.0; };
};

primitives:
{
    spheres = (
        { 
            center = { x = -1.0; y = 1.0; z = -5.0; }; 
            radius = 0.5; 
            color = { r = 1.0; g = 0.0; b = 0.0; }; 
        }
    );
    
    planes = (
        { 
            point = { x = 0.0; y = -1.0; z = 0.0; }; 
            normal = { x = 0.0; y = 1.0; z = 0.0; }; 
            color = { r = 0.5; g = 0.5; b = 0.5; }; 
        }
    );
    
    cylinders = (
        { 
            center = { x = 0.0; y = 0.0; z = -3.0; }; 
            radius = 0.3; 
            color = { r = 0.0; g = 1.0; b = 0.0; }; 
        }
    );
    
    cones = (
        { 
            apex = { x = 0.0; y = 0.0; z = -3.0; }; 
            radius = 0.5; 
            height = 1.0; 
            rotation = { x = 0.0; y = 45.0; z = 0.0; }; 
            color = { r = 1.0; g = 1.0; b = 0.0; }; 
        }
    );
    
    limited_cylinders = (
        { 
            center = { x = 0.0; y = 0.0; z = -4.0; }; 
            radius = 0.2; 
            height = 1.0; 
            color = { r = 0.0; g = 0.5; b = 1.0; }; 
        }
    );
    
    limited_cones = (
        { 
            apex = { x = 0.0; y = 0.0; z = -4.0; }; 
            radius = 0.3; 
            height = 1.0; 
            color = { r = 1.0; g = 0.5; b = 0.0; }; 
        }
    );
};

lights:
{
    ambient = (
        { intensity = 0.2; }
    );
    
    directional = (
        { 
            direction = { x = 1.0; y = -1.0; z = -0.5; }; 
            intensity = 0.8; 
        }
    );
    
    point = (
        { 
            position = { x = 2.0; y = 2.0; z = 0.0; }; 
            intensity = 0.6; 
        }
    );
    
    colored = (
        { 
            position = { x = -2.0; y = 2.0; z = 0.0; }; 
            intensity = 0.5; 
            color = { r = 0.5; g = 0.0; b = 1.0; }; 
        }
    );
};
```

### Configuration Parameters

#### Camera
- `position` - Camera position in 3D space (x, y, z coordinates)

#### Primitives
All primitives require:
- `color` - RGB values (0.0 to 1.0)

**Sphere parameters:**
- `center` - Center position (x, y, z)
- `radius` - Sphere radius

**Plane parameters:**
- `point` - Any point on the plane (x, y, z)
- `normal` - Normal vector to the plane (x, y, z)

**Cylinder parameters:**
- `center` - Center of the cylinder's base (x, y, z)
- `radius` - Cylinder radius

**Cone parameters:**
- `apex` - Tip of the cone (x, y, z)
- `radius` - Base radius
- `height` - Cone height
- `rotation` - Optional rotation angles (x, y, z) in degrees

**Limited Cylinder/Cone parameters:**
- Same as infinite versions plus:
- `height` - Defines the extent of the primitive

#### Lights
**Ambient light:**
- `intensity` - Light intensity (0.0 to 1.0+)

**Directional light:**
- `direction` - Light direction vector (x, y, z)
- `intensity` - Light intensity

**Point light** ⭐
- `position` - Light position (x, y, z)
- `intensity` - Light intensity

**Colored light** ⭐
- `position` - Light position (x, y, z)
- `intensity` - Light intensity
- `color` - RGB color values (optional, defaults to white)

## Example Scenes

Several pre-configured scenes are included in the `configs/` directory:
- `scene.cfg` - Basic scene with mixed primitives
- `test.cfg` - Simple test configuration
- `gallery.cfg` - Art gallery scene
- `museum.cfg` - Museum exhibition
- `backrooms.cfg` - Surreal backrooms scene
- `scifi_corridor.cfg` - Science fiction corridor
- `plateau.cfg` - Landscape scene

Generate images from any scene:
```bash
./raytracer configs/gallery.cfg > gallery.ppm
./raytracer configs/museum.cfg > museum.ppm
./raytracer configs/backrooms.cfg > backrooms.ppm
```

## Output Format

The raytracer outputs images in **PPM (Portable Pixmap) format**:
- **Magic number:** P3 (ASCII PPM format)
- **Resolution:** Width and height in pixels (configurable in Config.hpp)
- **Color depth:** 8-bit per channel (0-255)
- **Colors:** RGB, one pixel per line

## Project Structure

```
raytracer/
├── src/                        # Source code
│   ├── main.cpp               # Entry point and rendering loop
│   ├── Camera/                # Camera implementation
│   ├── Math/                  # Vector and point math
│   ├── Primitives/            # Geometric primitives
│   ├── Lights/                # Lighting system
│   ├── Light_bonus/           # Bonus light types
│   ├── Factory/               # Object factory patterns
│   ├── Scene/                 # Scene management
│   ├── Rotation/              # Rotation transformations
│   └── Transformations_bonus/ # Scale and shear
├── includes/                  # Header files (.hpp)
├── configs/                   # Scene configuration files
├── build/                     # Compiled object files (generated)
└── Makefile                   # Build configuration
```

## Technical Details

### Ray-Primitive Intersection
The engine uses mathematical formulas to find where rays intersect with geometric primitives:
- **Sphere:** Quadratic equation solving
- **Plane:** Linear plane-ray intersection
- **Cylinder/Cone:** Parametric surface equations

### Lighting Model
- **Ambient:** Flat global illumination
- **Diffuse:** Surface normal-based shading
- **Phong-like:** Realistic lighting based on angles

### Coordinate System
- Right-handed 3D coordinate system (x, y, z)
- Y-axis typically points up
- Z-axis typically points toward/away from viewer

## Performance

The raytracer is optimized with:
- `-O2` compiler optimization flag
- Early ray termination (no intersection = black)
- Efficient geometric calculations
- Clang++ compilation for faster execution

## Notes

- Configuration files use libconfig++ syntax
- Color values are normalized (0.0 to 1.0)
- Light intensity values can exceed 1.0 for brighter effects
- PPM output goes to stdout for easy piping and redirection
- Scene complexity affects render time
